#ifndef TRACE_PARSER_PARSER_CREATOR_H
#define TRACE_PARSER_PARSER_CREATOR_H

#include "AbstractParser.h"

class ParserCreator {

  public:
    virtual AbstractParser* factoryMethod() = 0;

    AbstractParser* createParser();

};

#endif // TRACE_PARSER_PARSER_CREATOR_H