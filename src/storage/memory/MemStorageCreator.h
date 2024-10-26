#ifndef TRACE_STORAGE_MEMORY_MEM_STORAGE_CRATOR_H
#define TRACE_STORAGE_MEMORY_MEM_STORAGE_CRATOR_H

#include "../StorageCreator.h"
#include "../AbstractStorage.h"
#include "MemStorage.h"

class MemStorageCreator : public StorageCreator {

  public:
    AbstractStorage* factoryMethod() override {
      return new MemStorage{};
    }
};


#endif // TRACE_STORAGE_MEMORY_MEM_STORAGE_CRATOR_H