#ifndef TRACE_PARSER_HTTP_HTTP_PARSER_CREATOR_H
#define TRACE_PARSER_HTTP_HTTP_PARSER_CREATOR_H

#include "../AbstractParser.h"
#include "../ParserCreator.h"

class HttpParserCreator : public ParserCreator {

  public:
    AbstractParser* factoryMethod() override;
};

#endif // TRACE_PARSER_HTTP_HTTP_PARSER_CREATOR_H