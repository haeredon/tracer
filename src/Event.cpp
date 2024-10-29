#include "Event.h"

Event::Event(const uint8_t* data, const std::chrono::time_point<std::chrono::system_clock> timestamp) : data(data), timestamp(timestamp) {
    
}

const uint8_t* Event::getData() {
    return this->data;
}

const std::chrono::time_point<std::chrono::system_clock> Event::getTimestamp() {
    return this->timestamp;
}