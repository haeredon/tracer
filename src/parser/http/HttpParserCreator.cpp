#include "../ParserCreator.h"
#include "../AbstractParser.h"
#include "HttpParserCreator.h"

class HttpParserCreator : public ParserCreator {

  public:
    AbstractParser* factoryMethod() override {
      return new HttpParser{};
    }
};