#include "Tracer.h"
#include "monitor/AbstractMonitor.h"
#include "monitor/network/NetworkMonitorCreator.h"
#include "EventDistributer.h"

void Tracer::initialize() { 
    EventDistributer* distributer = new EventDistributer(2, 1);


    NetworkMonitorCreator networkMonitorCreator;
    AbstractMonitor* networkMonitor = networkMonitorCreator.createMonitor("192.168.0.117");
    networkMonitor->addDistributer(distributer);
    this->monitorMap[MONITOR_TYPE::NETWORK] = networkMonitor;

}

void Tracer::reportNetwork() {
    
}

void Tracer::reportError() {

}

void Tracer::reportCustom() {
    
}

