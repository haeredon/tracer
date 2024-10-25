// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// TODO 5: Include MathFunctions.h
#include "config.h"


/*********************************** ENTITY_CONTAINER START **********************************/
/*********************************** ENTITY_CONTAINER END **********************************/

/*********************************** STORAGE START **********************************/
/*********************************** STORAGE END **********************************/

/*********************************** METADATA START **********************************/
class Event {


};

/*********************************** METADATA END **********************************/
/*********************************** PARSERS START **********************************/

class AbstractParser {

  public:
    virtual std::vector<Event>& parse() = 0;

};

class HttpParser : public AbstractParser {

  public:
    std::vector<Event>& parse() {
      std::cout << "KAGEMAND" << std::endl;
      std::vector<Event> bla = {};
      return bla;
    }

};

class ParserCreator {

  public:
    virtual AbstractParser* factoryMethod() = 0;

    AbstractParser* createParser() {
      return this->factoryMethod();
    }

};

class HttpParserCreator : public ParserCreator {

  public:
    AbstractParser* factoryMethod() override {
      return new HttpParser{};
    }
};

/*********************************** PARSERS END **********************************/




void kage(uint32_t span_id, std::vector<uint8_t> data) {
  ParserCreator* httpParserCreator = new HttpParserCreator{};

  AbstractParser* httpParser = httpParserCreator->createParser();

  httpParser->parse();
  


}


int main(int argc, char* argv[])
{
  std::vector<uint8_t> data = { 1,2,3,4,5,6,7,8,9 };

  kage(1, data);



  // get vector of network data
  // parse out the span id
  // save to some virtual storage





  if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]);

  // TODO 6: Replace sqrt with mathfunctions::sqrt

  // calculate square root
  const double outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}         


