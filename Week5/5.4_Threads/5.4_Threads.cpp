#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <string>

class BinarySemaphore {
    std::mutex mtx;
    std::condition_variable cv;
    bool available;

public:
    BinarySemaphore(int initial = 1) : available(initial > 0) {}

    void acquire() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return available; });
        available = false;
    }

    void release() {
        std::lock_guard<std::mutex> lock(mtx);
        available = true;
        cv.notify_one();
    }
};

BinarySemaphore sema(1); 

void print_thread(const std::string& name, const std::string& msg) {
    sema.acquire();
    for (char c : msg) {
        std::cout << name << ": " << c << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    sema.release();
}

int main() {
    std::thread t1(print_thread, "A", "Thread A zegt hallo!");
    std::thread t2(print_thread, "B", "Thread B groet je!");
    std::thread t3(print_thread, "C", "Thread C is ook hier!");

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Alle threads klaar.\n";
    return 0;
}
