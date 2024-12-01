#ifndef TRACE_AGENT_H
#define TRACE_AGENT_H

#include <cstdint>

#include "Tracer.h"
#include "EventDistributer.h"
#include "storage/network/NetworkStorage.h"


template<class DISTRIBUTER_T>
class Agent {

  private:

    uint64_t entityId;

    DISTRIBUTER_T* eventDistributer;

  public:

    Agent(uint64_t entityId) : entityId(entityId) {
        this->eventDistributer = new DISTRIBUTER_T {};
    }

    void initialize() {

    }

    Tracer<DISTRIBUTER_T> getTracer() {
        return Tracer<DISTRIBUTER_T> { this->entityId, this->eventDistributer };         
    }


};


using TracerAgent = Agent<EventDistributer<NetworkStorage<int>>>;



#endif // TRACE_AGENT_H