#include <unistd.h>
#include <chrono>

#include "Tracer.h"
#include "monitor/AbstractMonitor.h"
#include "monitor/network/NetworkMonitorCreator.h"
#include "EventDistributer.h"
#include "storage/AbstractStorage.h"
#include "storage/memory/MemStorageCreator.h"


Tracer::Tracer(uint64_t entityId, EventDistributer& EventDistributer) : 
    entityId(entityId), eventDistributer(eventDistributer) {

}


TraceTag Tracer::getTraceTag() {
    return TraceTag { entityId, std::chrono::steady_clock::now() };
}

void Tracer::start() {
    this->event.setStartTime(std::chrono::system_clock::now());
}

void Tracer::end() {    
    this->event.setEndTime(std::chrono::system_clock::now());
    this->distributer.distribute(event);

    // store 
    //   entityId
    //   start and endtime
    //   traceTag
}

void Tracer::registerIncoming(TraceTag&& traceTag) {
    this->event.setTag(std::forward<TraceTag>(traceTag));

    // store 
    //   entityId
    //   traceTag
    //   
    
}