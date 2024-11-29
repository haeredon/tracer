#ifndef TRACE_TRACE_TAG_H
#define TRACE_TRACE_TAG_H

#include <chrono>
#include <cstdint>
#include <string>

class TraceTag {

    private:

        uint64_t entityId;
        uint64_t spanId;
        std::chrono::steady_clock::time_point time;

    public:

        TraceTag(uint64_t entityId, std::chrono::steady_clock::time_point time);

        TraceTag(uint8_t* bytes, size_t size);

        // std::string toBase64();

        // std::vector toBytes();

        std::string toString();
};


#endif // TRACE_TRACE_TAG_H