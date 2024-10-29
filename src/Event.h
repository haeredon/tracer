#ifndef TRACE_EVENT_H
#define TRACE_EVENT_H

#include <chrono>

class Event {

    private:

        const uint8_t* data;
        const std::chrono::time_point<std::chrono::system_clock> timestamp;

    public:
        
        Event(const uint8_t* data, const std::chrono::time_point<std::chrono::system_clock> timestamp);

        const uint8_t* getData();

        const std::chrono::time_point<std::chrono::system_clock> getTimestamp();
};


#endif // TRACE_EVENT_H