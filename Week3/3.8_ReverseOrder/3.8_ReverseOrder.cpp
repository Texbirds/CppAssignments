#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    const std::string filename = "Exercise3_8.txt";
    std::ifstream inFile(filename);

    if (!inFile) {
        std::cerr << "Error: Cannot open file \"" << filename << "\"." << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    int value;

    while (inFile >> value) {
        numbers.push_back(value);
    }

    inFile.close();

    if (numbers.size() != 20) {
        std::cerr << "Error: File must contain exactly 20 integers." << std::endl;
        return 1;
    }

    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Cannot write to file \"" << filename << "\"." << std::endl;
        return 1;
    }

    for (int num : numbers) {
        outFile << num << " ";
    }

    outFile.close();

    std::cout << "The numbers have been sorted in descending order and written back to the file.\n";

    return 0;
}
