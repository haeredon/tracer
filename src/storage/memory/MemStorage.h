#ifndef TRACE_STORAGE_MEMORY_MEM_STORAGE_H
#define TRACE_STORAGE_MEMORY_MEM_STORAGE_H

#include <chrono>

#include "../AbstractStorage.h"

class MemStorage : public AbstractStorage {

  public:
    void write(uint64_t entityId, uint64_t scaleId, const std::chrono::time_point<std::chrono::system_clock> timestamp, const uint8_t* data);

};


#endif // TRACE_STORAGE_MEMORY_MEM_STORAGE_H