#include "NetworkMonitorCreator.h"
#include "NetworkMonitor.h"

AbstractMonitor* NetworkMonitorCreator::factoryMethod(std::string kage) {
  return new NetworkMonitor{kage};
}