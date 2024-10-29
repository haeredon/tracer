#ifndef TRACE_MONITOR_NETWORK_NETWORK_MONITOR_H
#define TRACE_MONITOR_NETWORK_NETWORK_MONITOR_H

#include <cstdint>
#include <vector>
#include <string>
#include "PcapLiveDeviceList.h"

#include "../AbstractMonitor.h"

class NetworkMonitor : public AbstractMonitor {

  private:
  
    std::string addr;

    pcpp::PcapLiveDevice* captureDevice;

    static void packetArrival(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie);

  public:

    NetworkMonitor(std::string ipv4);

    void start();

    void stop();

    void addParser();

    void addDistributer(EventDistributer* eventDistributer);

};


#endif // TRACE_MONITOR_NETWORK_NETWORK_MONITOR_H