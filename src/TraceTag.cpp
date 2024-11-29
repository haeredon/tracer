#include "TraceTag.h"


TraceTag::TraceTag(uint64_t entityId, std::chrono::steady_clock::time_point time) :
    entityId(entityId), time(time) {
    
}

TraceTag::TraceTag(uint8_t* bytes, size_t size) {
    entityId = 1;
    time = std::chrono::steady_clock::now();
}

std::string TraceTag::toString() {
    return std::to_string(entityId) + ":" + std::to_string(time.time_since_epoch().count());
}