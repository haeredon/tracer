#ifndef TRACE_STORAGE_STORAGE_CREATOR_H
#define TRACE_STORAGE_STORAGE_CREATOR_H

#include "AbstractStorage.h"

class StorageCreator {

  public:
    virtual AbstractStorage* factoryMethod() = 0;

    AbstractStorage* createStorage();

};


#endif // TRACE_STORAGE_STORAGE_CREATOR_H