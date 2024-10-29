#ifndef TRACE_MONITOR_ABSTRACT_MONITOR_H
#define TRACE_MONITOR_ABSTRACT_MONITOR_H

#include "../EventDistributer.h"

class AbstractMonitor {

    public:

        virtual void start() = 0;
        virtual void stop() = 0;

        virtual void addParser() = 0;

        virtual void addDistributer(EventDistributer* eventDistributer) = 0;

};

#endif // TRACE_MONITOR_ABSTRACT_MONITOR_H