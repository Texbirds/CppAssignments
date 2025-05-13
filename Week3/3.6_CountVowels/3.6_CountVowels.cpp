#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

bool isVowel(char ch) {
    ch = std::tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    std::string filename;
    std::cout << "Enter a file name: ";
    std::getline(std::cin, filename);

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file \"" << filename << "\"." << std::endl;
        return 1;
    }

    int vowelCount = 0;
    char ch;
    while (file.get(ch)) {
        if (isVowel(ch)) {
            ++vowelCount;
        }
    }

    file.close();

    std::cout << "Number of vowels in the file: " << vowelCount << std::endl;
    return 0;
}
