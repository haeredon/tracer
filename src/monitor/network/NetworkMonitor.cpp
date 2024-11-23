#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

#include "stdlib.h"
#include "PcapLiveDeviceList.h"
#include "SystemUtils.h"

#include "NetworkMonitor.h"
#include "../../EventDistributer.h"
#include "../../Event.h"

NetworkMonitor::NetworkMonitor(std::string ipv4) {
    this->addr = ipv4;
}

void NetworkMonitor::start() {
    this->captureDevice = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(this->addr);

    if (this->captureDevice == nullptr) {
        std::cerr << "Cannot find interface with IPv4 address of '" << this->addr << "'" << std::endl;
        throw;
    }

      // open the device before start capturing/sending packets
    if (!this->captureDevice->open()) {
        std::cerr << "Cannot open device" << std::endl;
        throw;
    } 

    this->captureDevice->startCapture(NetworkMonitor::packetArrival, this);
}

void NetworkMonitor::stop() {
    this->captureDevice->stopCapture();
}

void NetworkMonitor::addDistributer(EventDistributer* eventDistributer) {
    this->distributers.push_back(eventDistributer);
}

void NetworkMonitor::packetArrival(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* self) {
    std::cout << "NetworkMonitor::packetArrival()" << std::endl;

    NetworkMonitor* monitor = static_cast<NetworkMonitor*>(self);

    for (std::vector<EventDistributer*>::iterator it = monitor->distributers.begin(); it != monitor->distributers.end(); ++it) {
        (*it)->distribute(Event(packet->getRawData(), std::chrono::system_clock::now()));
    };    
}