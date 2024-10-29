#ifndef TRACE_EVENT_DISTRIBUTER_H
#define TRACE_EVENT_DISTRIBUTER_H

#include "Event.h"

#include <cstdint>

class EventDistributer {


    public:

        EventDistributer(uint64_t entityId, uint64_t scaleId);

        void distribute(Event&& event);

};

#endif // TRACE_EVENT_DISTRIBUTER_H