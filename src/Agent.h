#ifndef TRACE_AGENT_H
#define TRACE_AGENT_H

#include <cstdint>

#include "Tracer.h"

enum class MONITOR_TYPE {
    NETWORK,
    SYSTEM
};

class Agent {

  private:

    uint64_t entityId;

  public:

    Agent(uint64_t entityId);

    void initialize();

    Tracer getTracer();


};


#endif // TRACE_AGENT_H