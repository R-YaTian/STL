#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <vector>
#include <latch>

void test_atomic_wait_notify() {
    std::cout << "Testing std::atomic_wait and std::atomic_notify\n";
    std::cout << "==============================================\n";

    std::atomic<int> data(0);
    std::latch latch(2);

    auto consumer = [&]() {
        std::cout << "Consumer thread started\n";
        latch.arrive_and_wait();

        std::cout << "Consumer waiting for data to become 1...\n";
        data.wait(0);

        std::cout << "Consumer detected data change to: " << data.load() << "\n";
    };

    auto producer = [&]() {
        std::cout << "Producer thread started\n";
        latch.arrive_and_wait();

        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "Producer changing data to 1\n";
        data.store(1);
        data.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::cout << "Producer changing data to 2\n";
        data.store(2);
        data.notify_all();
    };

    std::thread t1(consumer);
    std::thread t2(producer);

    t1.join();
    t2.join();

    std::cout << "Test completed successfully\n";
}

int main() {
    try {
        test_atomic_wait_notify();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}
