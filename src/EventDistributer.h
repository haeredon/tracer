#ifndef TRACE_EVENT_DISTRIBUTER_H
#define TRACE_EVENT_DISTRIBUTER_H

#include "events/Event.h"
#include "storage/AbstractStorage.h"
#include "utility/ProdConsQueue.h"

#include <cstdint>
#include <vector>

template<class STORAGE_T>
class EventDistributer {

    private:

        STORAGE_T& storage;

        ProdConsQueue<Event*, 256> queue; 

    public:

        EventDistributer(STORAGE_T& storage) : storage(storage) {
            
        }

        void distribute(Event* event) {
            queue.push(event);
            std::cout << "EventDistributer::distribute()" << std::endl;
        }

};

#endif // TRACE_EVENT_DISTRIBUTER_H