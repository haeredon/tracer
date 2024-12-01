#ifndef TRACE_EVENT_DISTRIBUTER_H
#define TRACE_EVENT_DISTRIBUTER_H

#include "events/Event.h"
#include "storage/AbstractStorage.h"
#include "utility/ProdConsQueue.h"

#include <cstdint>
#include <vector>
#include <iostream>

template<class QUEUE_T, class STORAGE_T, class EVENT_T, unsigned int QUEUE_SIZE>
class EventDistributer {

    private:

        STORAGE_T* storage;

        QUEUE_T queue; 

    public:

        EventDistributer() {
            this->storage = new STORAGE_T {};
        }
                        
        

        void distribute(EVENT_T& event) {
            queue.push(event);
            std::cout << "EventDistributer::distribute()" << std::endl;
        }

};

#endif // TRACE_EVENT_DISTRIBUTER_H