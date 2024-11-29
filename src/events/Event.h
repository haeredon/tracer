#ifndef TRACE_EVENTS_EVENT_H
#define TRACE_EVENTS_EVENT_H

#include <chrono>
#include <string>

class Event {

    public:

        virtual const std::string serialize() = 0;
        
};


#endif // TRACE_EVENTS_EVENT_H