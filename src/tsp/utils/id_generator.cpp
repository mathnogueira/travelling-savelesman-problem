#include <tsp/utils/id_generator.hpp>

IdGenerator::IdGenerator() {
    this->nextId = 1;
}

unsigned int IdGenerator::generateId() {
    return this->nextId++;
}