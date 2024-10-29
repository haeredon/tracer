#ifndef TRACE_MONITOR_NETWORK_NETWORK_MONITOR_CREATOR_H
#define TRACE_MONITOR_NETWORK_NETWORK_MONITOR_CREATOR_H

#include <cstdint>
#include <vector>
#include <string>

#include "../MonitorCreator.h"
#include "../AbstractMonitor.h"

class NetworkMonitorCreator : public MonitorCreator<std::string> {

  public:

      AbstractMonitor* factoryMethod(std::string ipv4);

};

#endif // TRACE_MONITOR_NETWORK_NETWORK_MONITOR_CREATOR_H