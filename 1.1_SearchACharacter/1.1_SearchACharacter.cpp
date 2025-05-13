#include <iostream>
#include <string>

bool search(std::string& s, char& key);

int main()
{
    //define variables
    std::string sentence;
    char letter;

    // obtain values from user
    std::cout << "Type a sentence\n";
    std::getline(std::cin, sentence);
    std::cout << "Type what letter you want to check for\n";
    std::cin >> letter;

    if (search(sentence, letter)) {
        std::cout << "The letter was found in the sentence";
    }
    else {
        std::cout << "The letter was NOT found in the sentence";
    }
}

bool search(std::string& s, char& key)
{
    return s.find(key) != std::string::npos;
}
