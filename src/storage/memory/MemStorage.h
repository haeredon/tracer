#ifndef TRACE_STORAGE_MEMORY_MEM_STORAGE_H
#define TRACE_STORAGE_MEMORY_MEM_STORAGE_H

#include "../AbstractStorage.h"

class MemStorage : public AbstractStorage {

  public:
    void write();

};


#endif // TRACE_STORAGE_MEMORY_MEM_STORAGE_H