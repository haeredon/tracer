#ifndef TRACE_TRACER_H
#define TRACE_TRACER_H

#include <cstdint>
#include <unordered_map>


#include "monitor/AbstractMonitor.h"
#include "TraceTag.h"
#include "events/HttpTraceEvent.h"

enum class MONITOR_TYPE {
    NETWORK,
    SYSTEM
};

class Tracer {

  private:

    uint64_t entityId;

    EventDistributer<int>& eventDistributer;

    TraceTag&& traceTag;

    HttpTraceEvent event;

  public:

    Tracer(uint64_t entityId, EventDistributer<int>& EventDistributer);

    TraceTag getTraceTag();

    void start();

    void end();

    void registerIncoming(TraceTag&& traceTag);

};


#endif // TRACE_TRACER_H