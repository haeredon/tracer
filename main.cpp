// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// TODO 5: Include MathFunctions.h
#include "config.h"

#include "src/Tracer.h"
#include "src/EventDistributer.h"
#include "src/digester/MonitorDigester.h"
#include "src/parser/http/HttpParserCreator.h"


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


