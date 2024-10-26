#include "StorageCreator.h"

AbstractStorage* StorageCreator::createStorage() {
    return this->factoryMethod();
}
