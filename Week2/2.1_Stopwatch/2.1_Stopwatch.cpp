#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

class StopWatch {
private:
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;

public:
    StopWatch() {
        startTime = std::chrono::steady_clock::now();
    }

    void start() {
        startTime = std::chrono::steady_clock::now();
    }

    void stop() {
        endTime = std::chrono::steady_clock::now();
    }

    long long getElapsedTime() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    }

    std::chrono::steady_clock::time_point getStartTime() const {
        return startTime;
    }

    std::chrono::steady_clock::time_point getEndTime() const {
        return endTime;
    }
};

int main() {
    const int SIZE = 100000;
    std::vector<int> numbers;

    for (int i = 0; i < SIZE; ++i) {
        numbers.push_back(rand());
    }

    StopWatch sw;
    sw.start();

    std::sort(numbers.begin(), numbers.end());

    sw.stop();

    std::cout << "Time taken to sort " << SIZE << " numbers: "
        << sw.getElapsedTime() << " milliseconds" << std::endl;

    return 0;
}
