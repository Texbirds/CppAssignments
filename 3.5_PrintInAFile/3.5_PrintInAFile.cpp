#include <iostream>
#include <fstream>
#include <string>

int main() {
    const std::string filename = "Exercise3_5.txt";
    std::ifstream inFile(filename);

    if (!inFile) {
        std::cerr << "File \"" << filename << "\" does not exist." << std::endl;
        return 1;
    }

    int charCount = 0;
    char ch;
    while (inFile.get(ch)) {
        ++charCount;
    }
    inFile.close();

    std::ofstream outFile(filename, std::ios::app);
    if (!outFile) {
        std::cerr << "Failed to open file for appending." << std::endl;
        return 1;
    }

    outFile << "\nNumber of characters: " << charCount << std::endl;
    outFile.close();

    std::cout << "Character count (" << charCount << ") appended to file." << std::endl;
    return 0;
}
