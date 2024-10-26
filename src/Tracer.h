#ifndef TRACE_TRACER_H
#define TRACE_TRACER_H

#include <cstdint>

class Tracer {

  private:

    static const uint8_t NETWORK_ID = 0;
    static const uint8_t ERROR_ID = 1;

  public:
    void reportNetwork();
    void reportError();
    void reportCustom();
};


#endif // TRACE_TRACER_H