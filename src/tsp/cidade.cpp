#include <tsp/models/cidade.hpp>

Cidade::Cidade() {

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