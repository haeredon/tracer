#include "HttpParserCreator.h"
#include "HttpParser.h"


AbstractParser* HttpParserCreator::factoryMethod() {
    return new HttpParser{};
}
