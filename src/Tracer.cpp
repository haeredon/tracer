#include <unistd.h>

#include "Tracer.h"
#include "monitor/AbstractMonitor.h"
#include "monitor/network/NetworkMonitorCreator.h"
#include "EventDistributer.h"
#include "storage/AbstractStorage.h"
#include "storage/memory/MemStorageCreator.h"




void Tracer::initialize() { 
    // factories
    MemStorageCreator memStorageCreator;
    NetworkMonitorCreator networkMonitorCreator;

    // initialize distributers
    AbstractStorage* memStorage = memStorageCreator.createStorage();
    EventDistributer* distributer = new EventDistributer(2, 1, memStorage);
    
    // initialize monitors
    AbstractMonitor* networkMonitor = networkMonitorCreator.createMonitor("192.168.0.117");
    networkMonitor->addDistributer(distributer);
    this->monitorMap[MONITOR_TYPE::NETWORK] = networkMonitor;

    networkMonitor->start();

    sleep(10);
}

void Tracer::reportNetwork() {
    
}

void Tracer::reportError() {

}

void Tracer::reportCustom() {
    
}

