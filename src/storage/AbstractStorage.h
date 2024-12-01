#ifndef TRACE_STORAGE_ABSTRACT_STORAGE_H
#define TRACE_STORAGE_ABSTRACT_STORAGE_H

#include <chrono>

class AbstractStorage {

  public:
    virtual void write(std::string& bytes) = 0;

};


#endif // TRACE_STORAGE_ABSTRACT_STORAGE_H