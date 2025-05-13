#include <iostream>
#include <string>

bool isStopCodon(const std::string& codon) {
    return codon == "TAG" || codon == "TTA" || codon == "TGA";
}

bool containsForbiddenTriplet(const std::string& gene) {
    for (size_t i = 0; i + 2 < gene.size(); i += 3) {
        std::string triplet = gene.substr(i, 3);
        if (triplet == "ATG" || triplet == "TAG" || triplet == "TTA" || triplet == "TGA") {
            return true;
        }
    }
    return false;
}

int main() {
    std::string genome;
    std::cout << "Enter a genome string: ";
    std::cin >> genome;

    bool foundGene = false;

    for (size_t i = 0; i + 2 < genome.size(); ++i) {
        if (genome.substr(i, 3) == "ATG") {
            for (size_t j = i + 3; j + 2 < genome.size(); j += 3) {
                std::string codon = genome.substr(j, 3);
                if (isStopCodon(codon)) {
                    std::string gene = genome.substr(i + 3, j - (i + 3));
                    if (gene.length() % 3 == 0 && !containsForbiddenTriplet(gene)) {
                        std::cout << gene << std::endl;
                        foundGene = true;
                    }
                    break;
                }
            }
        }
    }

    if (!foundGene) {
        std::cout << "no gene" << std::endl;
    }

    return 0;
}
