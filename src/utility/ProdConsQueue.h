#ifndef TRACE_UTILITY_PROD_CONS_QUEUE_H
#define TRACE_UTILITY_PROD_CONS_QUEUE_H

#include <chrono>
#include <atomic>

template<class ITEM_T, unsigned int SIZE>
class ProdConsQueue {

    private:

        std::atomic<int> readIdx {0};
        std::atomic<int> writeIdx {0};

        ITEM_T buffer[SIZE];

    public:

          void push(const ITEM_T& item) {
            int writeIndex = writeIdx.load(std::memory_order_relaxed);

            if((writeIndex + 1) % SIZE != readIdx.load(std::memory_order_acquire)) {
                buffer[writeIdx] = item;
                writeIdx.store(++writeIdx % SIZE, std::memory_order_release);
            } else {
                throw; // queue full
            }
        }

        void push(ITEM_T&& item) {
            int writeIndex = writeIdx.load(std::memory_order_relaxed);

            if((writeIndex + 1) % SIZE != readIdx.load(std::memory_order_acquire)) {
                buffer[writeIdx] = std::move(item);
                writeIdx.store(++writeIdx % SIZE, std::memory_order_release);
            } else {
                throw; // queue full
            }
        }

        void pop() {
            int readIndex = readIdx.load(std::memory_order_relaxed);

            if(readIndex != writeIdx.load(std::memory_order_acquire)) {
                buffer[readIdx].~ITEM_T();
                readIdx.store(++readIdx % SIZE, std::memory_order_release);
            } else {
                throw; // not data in queue
            }
        }

        ITEM_T& front() {
            int readIndex = readIdx.load(std::memory_order_relaxed);

            if(readIndex != writeIdx.load(std::memory_order_acquire)) {
                return buffer[readIdx];                
            } 
            
            return nullptr;            
        }
        
        
};


#endif // TRACE_UTILITY_PROD_CONS_QUEUE_H