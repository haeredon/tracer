#ifndef TRACE_TRACER_H
#define TRACE_TRACER_H

#include <cstdint>
#include <unordered_map>


#include "TraceTag.h"
#include "events/HttpTraceEvent.h"

enum class MONITOR_TYPE {
    NETWORK,
    SYSTEM
};

template<class DISTRIBUTER_T>
class Tracer {

  private:

    uint64_t entityId;

    DISTRIBUTER_T& eventDistributer;

    TraceTag traceTag;

    HttpTraceEvent event;

  public:

  Tracer(uint64_t entityId, DISTRIBUTER_T& EventDistributer) : 
    entityId(entityId), eventDistributer(eventDistributer), traceTag(entityId, std::chrono::steady_clock::now()) {}


  TraceTag& getTraceTag() {
      return traceTag;
  }

  void start() {
      this->event.setStartTime(std::chrono::system_clock::now());
  }

  void end() {    
      this->event.setEndTime(std::chrono::system_clock::now());
      this->eventDistributer.distribute(&event);

      // store 
      //   entityId
      //   start and endtime
      //   traceTag
  }

  void registerIncoming(TraceTag&& traceTag) {
      this->event.setTag(std::forward<TraceTag>(traceTag));

      // store 
      //   entityId
      //   traceTag
      //   
  }

};


#endif // TRACE_TRACER_H