#include "EventDistributer.h"

#include <cstdint>
#include <iostream>

EventDistributer::EventDistributer(uint64_t entityId, uint64_t scaleId, AbstractStorage* storage) : entityId(entityId), scaleId(scaleId), storage(storage) {

}

void EventDistributer::distribute(Event&& event) {
    std::cout << "EventDistributer::distribute()" << std::endl;

    storage->write(entityId, scaleId, event.getTimestamp(), event.getData());    
}