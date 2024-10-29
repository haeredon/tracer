#ifndef TRACE_EVENT_DISTRIBUTER_H
#define TRACE_EVENT_DISTRIBUTER_H

#include "Event.h"
#include "storage/AbstractStorage.h"

#include <cstdint>

class EventDistributer {

    private:

        uint64_t entityId;
        uint64_t scaleId;

        AbstractStorage* storage;

    public:

        EventDistributer(uint64_t entityId, uint64_t scaleId, AbstractStorage* storage);

        void distribute(Event&& event);

};

#endif // TRACE_EVENT_DISTRIBUTER_H