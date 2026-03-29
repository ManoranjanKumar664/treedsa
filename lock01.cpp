#include <atomic>
#include <thread>
#include <iostream>
#include <vector>

class Lock {
private:
    std::atomic<bool> locked;   // lock variable

public:
    Lock() : locked(false) {}

    // Acquire lock (busy waiting / spin)
    void acquire() {
        bool expected = false;
        while (!locked.compare_exchange_weak(expected, true, std::memory_order_acquire)) {
            expected = false; // reset expected after failed CAS
            // optional: std::this_thread::yield();
        }
    }

    // Release lock
    void release() {
        locked.store(false, std::memory_order_release);
    }
};

// Shared data
int counter = 0;
Lock myLock;

void criticalSection(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        myLock.acquire();   // entry section
        counter++;          // critical section
        myLock.release();   // exit section
    }
}

int main() {
    const int numThreads = 4;
    const int iterations = 100000;

    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(criticalSection, iterations);
    }

    for (auto &t : threads) {
        t.join();
    }

    std::cout << "Final counter value: " << counter << std::endl;
    // Expected = numThreads * iterations
    return 0;
}