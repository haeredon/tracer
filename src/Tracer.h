#ifndef TRACE_TRACER_H
#define TRACE_TRACER_H

#include <cstdint>
#include <unordered_map>

#include "monitor/AbstractMonitor.h"

enum class MONITOR_TYPE {
    NETWORK,
    SYSTEM
};

class Tracer {

  private:

    static const uint8_t NETWORK_ID = 0;
    static const uint8_t ERROR_ID = 1;

    std::unordered_map<MONITOR_TYPE, AbstractMonitor*> monitorMap;


  public:

    void initialize();
    void reportNetwork();
    void reportError();
    void reportCustom();
};


#endif // TRACE_TRACER_H