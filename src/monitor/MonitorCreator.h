#ifndef TRACE_MONITOR_MONITOR_CREATOR_H
#define TRACE_MONITOR_MONITOR_CREATOR_H

#include <cstdint>
#include <vector>
#include <string>

#include "AbstractMonitor.h"

template<class ARGS_T>
class MonitorCreator {

  public:
    virtual AbstractMonitor* factoryMethod(ARGS_T args) = 0;
    
    AbstractMonitor* createMonitor(ARGS_T args) {
        return this->factoryMethod(args);
    }   

};


#endif // TRACE_MONITOR_MONITOR_CREATOR_H