// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// TODO 5: Include MathFunctions.h
#include "config.h"


/*********************************** Tracer START **********************************/
class Tracer {

  private:

    static const uint8_t NETWORK_ID = 0;
    static const uint8_t ERROR_ID = 1;

  public:
    void reportNetwork();
    void reportError();
    void reportCustom();
};

/*********************************** Tracer END **********************************/


/*********************************** MonitorDigester START **********************************/
class MonitorDigester {

  public:
    void addParser(AbstractParser* parser);

    void addDistributer(EventDistributer* distributer);

    void digest(const uint32_t spanId, const std::vector<uint8_t>& data, const uint8_t type);

};
/*********************************** MonitorDigester END **********************************/


/*********************************** EventDistributer START **********************************/
class EventDistributer {

};
/*********************************** EventDistributer END **********************************/

/*********************************** STORAGE START **********************************/
class AbstractStorage {

  public:
    virtual void write() = 0;

};

class MemStorage : public AbstractStorage {

  public:
    void write() {
      std::cout << "Write to MemStorage" << std::endl;
    }

};

class StorageCreator {

  public:
    virtual AbstractStorage* factoryMethod() = 0;

    AbstractStorage* createStorage() {
      return this->factoryMethod();
    }

};

class MemStorageCreator : public StorageCreator {

  public:
    AbstractStorage* factoryMethod() override {
      return new MemStorage{};
    }
};


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



int main(int argc, char* argv[]) {
  // dummy data
  uint32_t spanId = 1;
  std::vector<uint8_t> data = { 1,2,3,4,5,6,7,8,9 };

  // initializing. Should be a one time thing when the application starts
  HttpParserCreator httpParserCreator;
  EventDistributer* eventDistributer = new EventDistributer{};

  MonitorDigester* monitorDigester = new MonitorDigester{};
  monitorDigester->addDistributer(eventDistributer);
  monitorDigester->addParser(httpParserCreator.createParser());

  // digest the incoming data
  monitorDigester->digest(spanId, data, 0);

  




  // if (argc < 2) {
  //   // report version
  //   std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
  //             << Tutorial_VERSION_MINOR << std::endl;
  //   std::cout << "Usage: " << argv[0] << " number" << std::endl;
  //   return 1;
  // }

  // // convert input to double
  // const double inputValue = std::stod(argv[1]);

  // // TODO 6: Replace sqrt with mathfunctions::sqrt

  // // calculate square root
  // const double outputValue = sqrt(inputValue);
  // std::cout << "The square root of " << inputValue << " is " << outputValue
  //           << std::endl;
  // return 0;
}         


