#ifndef TRACE_PARSER_ABSTRACT_PARSER_H
#define TRACE_PARSER_ABSTRACT_PARSER_H

#include <vector>

#include "../Event.h"

class AbstractParser {

  public:
    virtual std::vector<Event>& parse() = 0;

};

#endif // TRACE_PARSER_ABSTRACT_PARSER_H