#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;

const int BUFFER_SIZE = 5;
queue<int> buffer;
mutex mtx;
condition_variable buffer_cv;

void producer() {
    for (int i = 0; i < 10; ++i) {
        unique_lock<mutex> lock(mtx);
        buffer_cv.wait(lock, [] { return buffer.size() < BUFFER_SIZE; });
        buffer.push(i);
        lock.unlock();
        buffer_cv.notify_all();
        cout << "Produced item: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); // Simulate work
    }
}

void consumer() {
    for (int i = 0; i < 10; ++i) {
        unique_lock<mutex> lock(mtx);
        buffer_cv.wait(lock, [] { return !buffer.empty(); });
        int item = buffer.front();
        buffer.pop();
        lock.unlock();
        buffer_cv.notify_all();
        cout << "Consumed item: " << item << endl;
        this_thread::sleep_for(chrono::milliseconds(800)); // Simulate work
    }
}

int main() {
    thread producer_thread(producer);
    thread consumer_thread(consumer);
    
    producer_thread.join();
    consumer_thread.join();

    return 0;
}
