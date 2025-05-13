#include <iostream>
#include <fstream>
#include <string>

int main() {
    const std::string filename = "Exercise3_7.txt";
    std::ifstream inFile(filename);

    if (!inFile) {
        std::cerr << "Error: Could not open file \"" << filename << "\"." << std::endl;
        return 1;
    }

    int value;
    int sum = 0;
    int product = 1;
    int count = 0;

    while (inFile >> value) {
        sum += value;
        product *= value;
        ++count;
    }

    inFile.close();

    if (count != 6) {
        std::cerr << "Error: File must contain exactly six integers." << std::endl;
        return 1;
    }

    double average = static_cast<double>(sum) / count;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}