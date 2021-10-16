#include "Predicate.h"
Predicate::Predicate(Token *input) {
    id = input->value;
//    std::cout << id << std::endl;
}

void Predicate::addParameter(std::vector<Parameter*> input) {
    parameters = input;
}

void Predicate::stringPredicate(std::vector<Predicate> input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i).id << std::endl;
        for (int j = 0; j < input.at(i).parameters.size(); j++) {
            std::cout << input.at(i).parameters.at(j) << std::endl;
        }
    }
}

Predicate::~Predicate() = default;
Predicate::Predicate() = default;

