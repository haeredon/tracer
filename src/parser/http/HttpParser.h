#ifndef TRACE_PARSER_HTTP_HTTP_PARSER_H
#define TRACE_PARSER_HTTP_HTTP_PARSER_H

#include <vector>

#include "../../Event.h"
#include "../AbstractParser.h"

class HttpParser : public AbstractParser {

  public:
    std::vector<Event>& parse();

};

#endif // TRACE_PARSER_HTTP_HTTP_PARSER_H