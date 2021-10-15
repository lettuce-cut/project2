#include "Predicate.h"
Predicate::Predicate(Token *input) {
    id = input->value;
//    std::cout << id << std::endl;
}

void Predicate::addParameter(std::vector<Parameter*> input) {
    parameters = input;
}
void Predicate::predicateString(Predicate input) {
    std::cout << input.id << std::endl;
    for (int i = 0; i < input.parameters.size(); i++) {
        std::cout << input.parameters.at(i) << std::endl;
    }
}

Predicate::~Predicate() = default;
Predicate::Predicate() = default;
