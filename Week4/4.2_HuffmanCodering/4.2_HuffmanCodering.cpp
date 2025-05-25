#define PrintOutputBuildTree

#include <iostream>
#include <queue>
#include <map>
#include <climits> // for CHAR_BIT
#include <iterator>
#include <algorithm>
#include <fstream>

constexpr const int UniqueSymbols = 1 << CHAR_BIT;
constexpr const char* SampleString = "best wel veel eeeeeees";

using HuffCode = std::vector<bool>;
using HuffCodeMap = std::map<char, HuffCode>;

class INode {
public:
	const int frequency;

	virtual ~INode() {}
	virtual void printNode() = 0;

protected:
	INode(int freq) : frequency(freq) {}
};

class InternalNode : public INode {
public:
	INode* const left;
	INode* const right;

	InternalNode(INode* c0, INode* c1)
		: INode(c0->frequency + c1->frequency), left(c0), right(c1) {
	}

	~InternalNode() {
		delete left;
		delete right;
	}

	virtual void printNode() {
		std::cout << frequency << "(";
		left->printNode();
		std::cout << ",";
		right->printNode();
		std::cout << ")";
	}
};

class LeafNode : public INode {
public:
	const char c;

	LeafNode(int f, char c) : INode(f), c(c) {}

	virtual void printNode() {
		std::cout << "(" << frequency << "," << c << ")";
	}
};

struct NodeCmp {
	bool operator()(const INode* lhs, const INode* rhs) const { return lhs->frequency > rhs->frequency; }
};

INode* BuildTree(const int(&frequencies)[UniqueSymbols]) {
	std::priority_queue<INode*, std::vector<INode*>, NodeCmp> trees;

	for (int i = 0; i < UniqueSymbols; ++i) {
		if (frequencies[i] != 0)
			trees.push(new LeafNode(frequencies[i], (char)i));
	}

	//		std::priority_queue<INode*, std::vector<INode*>, NodeCmp> trees2(trees);
	//		while (!trees2.empty()) { trees2.top()->printNode(); trees2.pop(); std::cout << " "; }
	//		std::cout << std::endl;

	while (trees.size() > 1) {
		INode* childR = trees.top();
		trees.pop();

		INode* childL = trees.top();
		trees.pop();

		INode* parent = new InternalNode(childR, childL);
		trees.push(parent);

		//		std::priority_queue<INode*, std::vector<INode*>, NodeCmp> trees2(trees);
		//		while (!trees2.empty()) { trees2.top()->printNode(); trees2.pop(); std::cout << " "; }
		//		std::cout << std::endl;

	}
	return trees.top();
}

void GenerateCodes(const INode* node, const HuffCode& prefix, HuffCodeMap& outCodes) {
	if (const LeafNode* lf = dynamic_cast<const LeafNode*>(node)) {
		outCodes[lf->c] = prefix;
	}
	else if (const InternalNode* in = dynamic_cast<const InternalNode*>(node)) {
		HuffCode leftPrefix = prefix;
		leftPrefix.push_back(false);
		GenerateCodes(in->left, leftPrefix, outCodes);

		HuffCode rightPrefix = prefix;
		rightPrefix.push_back(true);
		GenerateCodes(in->right, rightPrefix, outCodes);
	}
}

std::string DecodeText(const std::vector<bool>& encoded, const INode* root) {
	std::string result;
	const INode* node = root;

	for (bool bit : encoded) {
		const InternalNode* internal = dynamic_cast<const InternalNode*>(node);
		if (!internal) break;

		node = bit ? internal->right : internal->left;

		if (const LeafNode* leaf = dynamic_cast<const LeafNode*>(node)) {
			result += leaf->c;
			node = root;  
		}
	}
	return result;
}

void SummarizeCompression(const char* originalText, const HuffCodeMap& codes) {
	size_t originalBits = strlen(originalText) * CHAR_BIT;
	size_t compressedBits = 0;

	for (const char* p = originalText; *p != '\0'; ++p)
		compressedBits += codes.at(*p).size();

	std::cout << "\nOriginal size:   " << originalBits << " bits" << std::endl;
	std::cout << "Compressed size: " << compressedBits << " bits" << std::endl;
	std::cout << "Compression ratio: "
		<< (100.0 * compressedBits / originalBits) << "%\n";
}

void EncodeToFile(const std::string& inputFile, const std::string& outputFile, const HuffCodeMap& codes) {
	std::ifstream in(inputFile, std::ios::binary);
	std::ofstream out(outputFile, std::ios::binary);

	char ch;
	std::vector<bool> encodedBits;
	while (in.get(ch)) {
		const HuffCode& code = codes.at(ch);
		encodedBits.insert(encodedBits.end(), code.begin(), code.end());
	}

	uint8_t byte = 0;
	int bitCount = 0;
	for (bool bit : encodedBits) {
		byte |= bit << (7 - bitCount++);
		if (bitCount == 8) {
			out.put(byte);
			byte = 0;
			bitCount = 0;
		}
	}
	if (bitCount > 0) out.put(byte);

	in.close();
	out.close();
}

std::string DecodeFromFile(const std::string& encodedFile, const INode* root) {
	std::ifstream in(encodedFile, std::ios::binary);
	std::vector<bool> bits;
	char byte;

	while (in.get(byte)) {
		for (int i = 7; i >= 0; --i)
			bits.push_back((byte >> i) & 1);
	}
	in.close();
	return DecodeText(bits, root);
}


int main() {
	int frequencies[UniqueSymbols] = { 0 };
	const char* ptr = SampleString;
	while (*ptr != '\0')
		++frequencies[*ptr++];

	std::cout << "Character frequencies:\n";
	for (int i = 0; i < UniqueSymbols; i++) {
		if (frequencies[i] != 0)
			std::cout << static_cast<char>(i) << " : " << frequencies[i] << std::endl;
	}
	std::cout << std::endl;

	INode* root = BuildTree(frequencies);
	HuffCodeMap codes;
	GenerateCodes(root, HuffCode(), codes);

	std::cout << "Huffman codes:\n";
	for (auto& code : codes) {
		std::cout << code.first << " ";
		std::copy(code.second.begin(), code.second.end(),
			std::ostream_iterator<bool>(std::cout));
		std::cout << std::endl;
	}

	std::ofstream sampleOut("input.txt");
	sampleOut << SampleString;
	sampleOut.close();

	EncodeToFile("input.txt", "encoded.bin", codes);

	std::string decodedText = DecodeFromFile("encoded.bin", root);
	std::cout << "\nDecoded text from file:\n" << decodedText << "\n";

	SummarizeCompression(SampleString, codes);

	delete root;
	return 0;
}
