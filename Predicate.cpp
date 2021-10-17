#include "Predicate.h"
Predicate::Predicate(Token *input) {
    id = input->value;
//    std::cout << id << std::endl;
}

void Predicate::addParameter(std::vector<Parameter*> input) {
    parameters = input;
}

void Predicate::stringPredicate(std::vector<Predicate> input) {
    for (auto & i : input) {
        std::cout << "  " << i.id << "(";
        for (long unsigned int j = 0; j < i.parameters.size(); j++) {
            if (j == i.parameters.size() - 1) {
                std::cout << i.parameters.at(j)->paramString() << ")";
            }
            else {
                std::cout << i.parameters.at(j)->paramString() << ",";
            }
        }
        std::cout << std::endl;
    }
//    std::cout << std::endl;
}

Predicate::~Predicate() = default;
Predicate::Predicate() = default;

