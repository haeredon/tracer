#ifndef TRACE_EVENT_DISTRIBUTER_H
#define TRACE_EVENT_DISTRIBUTER_H

#include "Event.h"
#include "storage/AbstractStorage.h"

#include <cstdint>

template<class STORAGE_T>
class EventDistributer {

    private:

        STORAGE_T& storage;

    public:

        EventDistributer(STORAGE_T& storage) : storage(storage) {
            
        }

        void distribute(Event&& event) {
            std::cout << "EventDistributer::distribute()" << std::endl;
        }

};

#endif // TRACE_EVENT_DISTRIBUTER_H