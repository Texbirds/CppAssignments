#include <iostream>
#include <string>

void count(const char s[], int counts[]);

int main()
{
    int counts[26] = { 0 };
    char str[100];

    std::cout << "Enter a string:";
    std::cin.getline(str, 100);

    count(str, counts);

    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            printf("%c: %d times\n", i + 'a', counts[i]);
        }
    }
}

void count(const char s[], int counts[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = tolower(s[i]);
        if (ch >= 'a' && ch <= 'z') {
            counts[ch - 'a']++;
        }
    }
}