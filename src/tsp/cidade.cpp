#include <tsp/models/cidade.hpp>

int Cidade::nextId = 1;

Cidade::Cidade() {
    this->id = Cidade::nextId++;
    this->prejuizo = 0;
    this->premio = 0;
}

Cidade::Cidade(unsigned int id) {
    this->id = id;
    this->prejuizo = 0;
    this->premio = 0;
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