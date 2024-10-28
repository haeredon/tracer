// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "stdlib.h"
#include "PcapLiveDeviceList.h"
#include "SystemUtils.h"

// TODO 5: Include MathFunctions.h
#include "config.h"

#include "src/Tracer.h"
#include "src/EventDistributer.h"
#include "src/digester/MonitorDigester.h"
#include "src/parser/http/HttpParserCreator.h"

/**
 * A struct for collecting packet statistics
 */
struct PacketStats
{
    int ethPacketCount = 0;
    int ipv4PacketCount = 0;
    int ipv6PacketCount = 0;
    int tcpPacketCount = 0;
    int udpPacketCount = 0;
    int dnsPacketCount = 0;
    int httpPacketCount = 0;
    int sslPacketCount = 0;


    /**
     * Clear all stats
     */
    void clear() { ethPacketCount = ipv4PacketCount = ipv6PacketCount = tcpPacketCount = udpPacketCount = dnsPacketCount = httpPacketCount = sslPacketCount = 0; }

    // Constructor is optional here since the members are already initialized
    PacketStats() = default;

    /**
     * Collect stats from a packet
     */
    void consumePacket(pcpp::Packet& packet)
    {
        if (packet.isPacketOfType(pcpp::Ethernet))
            ethPacketCount++;
        if (packet.isPacketOfType(pcpp::IPv4))
            ipv4PacketCount++;
        if (packet.isPacketOfType(pcpp::IPv6))
            ipv6PacketCount++;
        if (packet.isPacketOfType(pcpp::TCP))
            tcpPacketCount++;
        if (packet.isPacketOfType(pcpp::UDP))
            udpPacketCount++;
        if (packet.isPacketOfType(pcpp::DNS))
            dnsPacketCount++;
        if (packet.isPacketOfType(pcpp::HTTP))
            httpPacketCount++;
        if (packet.isPacketOfType(pcpp::SSL))
            sslPacketCount++;
    }

    /**
     * Print stats to console
     */
    void printToConsole()
    {
        std::cout
            << "Ethernet packet count: " << ethPacketCount << std::endl
            << "IPv4 packet count:     " << ipv4PacketCount << std::endl
            << "IPv6 packet count:     " << ipv6PacketCount << std::endl
            << "TCP packet count:      " << tcpPacketCount << std::endl
            << "UDP packet count:      " << udpPacketCount << std::endl
            << "DNS packet count:      " << dnsPacketCount << std::endl
            << "HTTP packet count:     " << httpPacketCount << std::endl
            << "SSL packet count:      " << sslPacketCount << std::endl;
    }
};

/**
 * A callback function for the async capture which is called each time a packet is captured
 */
static void onPacketArrives(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie) {
    // extract the stats object form the cookie
    auto* stats = static_cast<PacketStats*>(cookie);

    // parsed the raw packet
    pcpp::Packet parsedPacket(packet);

    // collect stats from packet
    stats->consumePacket(parsedPacket);
}



int main(int argc, char* argv[]) {
  // create the stats object
  PacketStats stats;

  // IPv4 address of the interface we want to sniff
  std::string interfaceIPAddr = "192.168.0.117";

  // find the interface by IP address
  auto* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(interfaceIPAddr);
  if (dev == nullptr) {
    std::cerr << "Cannot find interface with IPv4 address of '" << interfaceIPAddr << "'" << std::endl;
    return 1;
  }


  // before capturing packets let's print some info about this interface
  std::cout
    << "Interface info:" << std::endl
    << "   Interface name:        " << dev->getName() << std::endl // get interface name
    << "   Interface description: " << dev->getDesc() << std::endl // get interface description
    << "   MAC address:           " << dev->getMacAddress() << std::endl // get interface MAC address
    << "   Default gateway:       " << dev->getDefaultGateway() << std::endl // get default gateway
    << "   Interface MTU:         " << dev->getMtu() << std::endl; // get interface MTU

  if (!dev->getDnsServers().empty()) {
    std::cout << "   DNS server:            " << dev->getDnsServers().front() << std::endl;
  }

  // open the device before start capturing/sending packets
  if (!dev->open()) {
      std::cerr << "Cannot open device" << std::endl;
      return 1;
  } 

  std::cout << std::endl << "Starting async capture..." << std::endl;

  // start capture in async mode. Give a callback function to call to whenever a packet is captured and the stats object as the cookie
  dev->startCapture(onPacketArrives, &stats);

  // sleep for 10 seconds in main thread, in the meantime packets are captured in the async thread
  pcpp::multiPlatformSleep(10);

  // stop capturing packets
  dev->stopCapture();

  // print results
  std::cout << "Results:" << std::endl;
  stats.printToConsole();

  // dummy data
  // uint32_t spanId = 1;
  // std::vector<uint8_t> data(request, request + 1582);

  // // initializing. Should be a one time thing when the application starts
  // HttpParserCreator httpParserCreator;
  // EventDistributer* eventDistributer = new EventDistributer{};

  // MonitorDigester* monitorDigester = new MonitorDigester{};
  // monitorDigester->addDistributer(eventDistributer);
  // monitorDigester->addParser(httpParserCreator.createParser());

  // // digest the incoming data
  // monitorDigester->digest(spanId, data, 0);

  




  // if (argc < 2) {
  //   // report version
  //   std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
  //             << Tutorial_VERSION_MINOR << std::endl;
  //   std::cout << "Usage: " << argv[0] << " number" << std::endl;
  //   return 1;
  // }

  // // convert input to double
  // const double inputValue = std::stod(argv[1]);

  // // TODO 6: Replace sqrt with mathfunctions::sqrt

  // // calculate square root
  // const double outputValue = sqrt(inputValue);
  // std::cout << "The square root of " << inputValue << " is " << outputValue
  //           << std::endl;
  // return 0;
}         


