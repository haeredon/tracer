#ifndef TRACE_STORAGE_ABSTRACT_STORAGE_H
#define TRACE_STORAGE_ABSTRACT_STORAGE_H

#include <chrono>

class AbstractStorage {

  public:
    virtual void write(uint64_t entityId, uint64_t scaleId, const std::chrono::time_point<std::chrono::system_clock> timestamp, const uint8_t* data) = 0;

};


#endif // TRACE_STORAGE_ABSTRACT_STORAGE_H