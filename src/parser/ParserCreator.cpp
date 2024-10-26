#include "ParserCreator.h"


AbstractParser* ParserCreator::createParser() {
    return this->factoryMethod();
}

