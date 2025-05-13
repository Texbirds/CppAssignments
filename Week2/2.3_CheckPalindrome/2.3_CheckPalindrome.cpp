#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(const std::string& s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (std::tolower(s[left]) != std::tolower(s[right])) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    std::string lowered;
    for (char c : input) {
        lowered += std::tolower(c);
    }

    if (isPalindrome(input)) {
        std::cout << lowered << " is a palindrome" << std::endl;
    }
    else {
        std::cout << lowered << " is not a palindrome" << std::endl;
    }

    return 0;
}
