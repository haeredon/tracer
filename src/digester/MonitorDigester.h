#ifndef TRACE_DIGESTER_MONITOR_DIGESTER_H
#define TRACE_DIGESTER_MONITOR_DIGESTER_H

#include <cstdint>
#include <vector>

#include "../parser/AbstractParser.h"
#include "../EventDistributer.h"

class MonitorDigester {

  public:
    void addParser(AbstractParser* parser);

    void addDistributer(EventDistributer* distributer);

    void digest(const uint32_t spanId, const std::vector<uint8_t>& data, const uint8_t type);

};

#endif // TRACE_DIGESTER_MONITOR_DIGESTER_H