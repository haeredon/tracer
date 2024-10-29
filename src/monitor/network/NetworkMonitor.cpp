#include <iostream>
#include <algorithm>
#include "stdlib.h"
#include "PcapLiveDeviceList.h"
#include "SystemUtils.h"

#include "NetworkMonitor.h"
#include "../../EventDistributer.h"

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

void NetworkMonitor::addParser() {
    
}

void NetworkMonitor::addDistributer(EventDistributer* eventDistributer) {

}

void NetworkMonitor::packetArrival(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie) {

}