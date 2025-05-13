#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<typename T>
std::vector<T> intersect(const std::vector<T>& v1, const std::vector<T>& v2) {
    std::vector<T> result;
    for (const T& item : v1) {
        if (std::find(v2.begin(), v2.end(), item) != v2.end() &&
            std::find(result.begin(), result.end(), item) == result.end()) {
            result.push_back(item);
        }
    }
    return result;
}

int main() {
    std::vector<std::string> v1, v2;
    std::string input;

    std::cout << "Enter five strings for vector1:\n";
    for (int i = 0; i < 5; ++i) {
        std::cin >> input;
        v1.push_back(input);
    }

    std::cout << "Enter five strings for vector2:\n";
    for (int i = 0; i < 5; ++i) {
        std::cin >> input;
        v2.push_back(input);
    }

    std::vector<std::string> common = intersect(v1, v2);

    std::cout << "The common strings are";
    if (common.empty()) {
        std::cout << " (none)";
    }
    else {
        for (const std::string& s : common) {
            std::cout << " " << s;
        }
    }
    std::cout << std::endl;

    return 0;
}
