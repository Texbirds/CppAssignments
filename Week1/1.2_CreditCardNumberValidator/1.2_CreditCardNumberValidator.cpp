#include <iostream>

bool isValid(const std::string& cardNumber);
int sumOfDoubleEvenPlace(const std::string& cardNumber);
int getDigit(int number);
int sumOfOddPlace(const std::string& cardNumber);
bool startsWith(const std::string& cardNumber, const std::string& substr);


int main()
{
    std::string cardNumber;
    std::cout << "Write the number of your card\n";
    std::cin >> cardNumber;

    isValid(cardNumber);
}

// Return true if the card number is valid
bool isValid(const std::string& cardNumber)
{
    if (!(startsWith(cardNumber, "4") ||
        startsWith(cardNumber, "5") ||
        startsWith(cardNumber, "6") ||
        startsWith(cardNumber, "37")))
    {
        std::cout << "The number is invalid, it doesnt start with a proper integer";
        return false;
    }

    if (cardNumber.length() < 13 || cardNumber.length() > 16) {
        std::cout << "The number is invalid, it's not the right size (between 13 and 16 numbers)";
        return false;
    }

    int result = sumOfDoubleEvenPlace(cardNumber) + sumOfOddPlace(cardNumber);
    if (result % 10 == 0) {
        std::cout << result << " is a valid number!";
    }
    else
    {
        std::cout << result << " is not valid number!";
    }
}

// Get the result from Step 2
int sumOfDoubleEvenPlace(const std::string& cardNumber)
{
    int total = 0;
    for (int i = cardNumber.length() - 2; i >= 0; i -= 2) {
        int digit = cardNumber.at(i) - '0';
        total += getDigit(digit * 2);
    }
    std::cout << "Sum of doubled even-place digits: " << total << std::endl;
    return total;
}

// Return this number if it is a single digit, otherwise,
// return the sum of the two digits
int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    else {
        return ((number / 10) + (number % 10));
    }
}

// Return sum of odd-place digits in the card number
int sumOfOddPlace(const std::string& cardNumber) {
    int total = 0;
    for (int i = cardNumber.length() - 1; i >= 0; i -= 2) {
        int digit = cardNumber.at(i) - '0';
        total += digit;
    }
    std::cout << "Sum of odd-place digits: " << total << std::endl;
    return total;
}

// Return true if substr is the prefix for cardNumber
bool startsWith(const std::string& cardNumber, const std::string& substr) {
    return cardNumber.size() >= substr.size() &&
        cardNumber.substr(0, substr.size()) == substr;
}