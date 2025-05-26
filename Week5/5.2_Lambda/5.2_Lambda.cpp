#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

typedef std::function<void(const std::vector<int>&, int&)> myTypeFunc;

int main() {
    std::vector<int> getallen = { 1, 2, 3, 4, 5 };

    int som = 0;

    myTypeFunc optellen = [](const std::vector<int>& vec, int& result) {
        std::for_each(vec.begin(), vec.end(), [&result](int x) {
            result += x;
            });
        };

    optellen(getallen, som);

    std::cout << "De som van de getallen is: " << som << std::endl;

    return 0;
}
