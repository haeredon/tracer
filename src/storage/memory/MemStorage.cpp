#include <chrono>
#include <iostream>

#include "MemStorage.h"


void MemStorage::write(uint64_t entityId, uint64_t scaleId, const std::chrono::time_point<std::chrono::system_clock> timestamp, const uint8_t* data) {
    std::cout << "Write()" << std::endl;
}