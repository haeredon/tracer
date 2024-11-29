#ifndef TRACE_EVENTS_HTTP_TRACE_EVENT_H
#define TRACE_EVENTS_HTTP_TRACE_EVENT_H

#include <chrono>

#include "Event.h"
#include "TraceTag.h"

class HttpTraceEvent : public Event {

    public:
        
        HttpTraceEvent();

        const std::string serialize() override;

        void setTag(TraceTag&& traceTag);

        void setStartTime(const std::chrono::time_point<std::chrono::system_clock>& time);

        void setEndTime(const std::chrono::time_point<std::chrono::system_clock>& end);

};


#endif // TRACE_EVENTS_HTTP_TRACE_EVENT_H