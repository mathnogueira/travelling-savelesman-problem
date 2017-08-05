#include <tsp/models/cidade.hpp>

Cidade::Cidade(unsigned int id) {
    this->id = id;
    this->prejuizo = 0;
    this->premio = 0;
}

Cidade::Cidade(unsigned int id, float premio, float prejuizo) {
    this->id = id;
    this->prejuizo = prejuizo;
    this->premio = premio;
}

Cidade::Cidade(IdGenerator &idGenerator, float premio, float prejuizo) {
    this->id = idGenerator.generateId();
    this->prejuizo = prejuizo;
    this->premio = premio;
}

Cidade::~Cidade() {

}


float Cidade::getPrejuizo() {
    return this->prejuizo;
}

void Cidade::setPrejuizo(float prejuizo) {
    this->prejuizo = prejuizo;
}

float Cidade::getPremio() {
    return this->premio;
}

void Cidade::setPremio(float premio) {
    this->premio = premio;
}