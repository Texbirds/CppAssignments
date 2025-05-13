#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void intersect(std::vector<T>& v) {
    std::vector<T> result;

    for (const T& item : v) {
        if (std::find(result.begin(), result.end(), item) == result.end()) {
            result.push_back(item);
        }
    }

    v = result; 
}

int main() {
    std::vector<int> numbers;
    int input;

    std::cout << "Enter ten integers: ";
    for (int i = 0; i < 10; ++i) {
        std::cin >> input;
        numbers.push_back(input);
    }

    intersect(numbers); 

    std::cout << "The distinct integers are";
    for (int num : numbers) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
