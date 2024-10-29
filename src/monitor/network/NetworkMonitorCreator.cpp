#include "NetworkMonitorCreator.h"
#include "NetworkMonitor.h"

AbstractMonitor* NetworkMonitorCreator::factoryMethod(std::string ipv4) {
  return new NetworkMonitor{ipv4};
}