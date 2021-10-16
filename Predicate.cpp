#include "Predicate.h"
Predicate::Predicate(Token *input) {
    id = input->value;
    std::cout << id << std::endl;
}

void Predicate::addParameter(std::vector<Parameter*> input) {
    parameters = input;
}


Predicate::~Predicate() = default;
Predicate::Predicate() = default;
