#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

void playGame(const std::string& word) {
    std::string guessed(word.length(), '*');
    std::vector<char> triedLetters;
    int misses = 0;

    while (guessed != word) {
        std::cout << "(Guess) Enter a letter in the word " << guessed << " > ";
        char guess;
        std::cin >> guess;

        guess = std::tolower(guess);

        if (guessed.find(guess) != std::string::npos) {
            std::cout << "    " << guess << " is already in the word\n";
            continue;
        }
        if (std::find(triedLetters.begin(), triedLetters.end(), guess) != triedLetters.end()) {
            std::cout << "    " << guess << " is already tried and incorrect\n";
            continue;
        }

        bool correct = false;
        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == guess) {
                guessed[i] = guess;
                correct = true;
            }
        }

        if (!correct) {
            std::cout << "    " << guess << " is not in the word\n";
            ++misses;
            triedLetters.push_back(guess);
        }
    }

    std::cout << "The word is " << word << ". You missed " << misses << " time";
    if (misses != 1) std::cout << "s";
    std::cout << ".\n";
}

int main() {
    std::vector<std::string> words = { "write", "that", "school", "program", "hangman", "student", "vector", "object" };
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    char again = 'y';
    while (again == 'y') {
        std::string word = words[std::rand() % words.size()];
        playGame(word);
        std::cout << "\nDo you want to guess for another word? Enter y or n > ";
        std::cin >> again;
        again = std::tolower(again);
        std::cout << std::endl;
    }

    return 0;
}