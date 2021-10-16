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
        std::cout << "  " << input.at(i).id << "(";
        for (int j = 0; j < input.at(i).parameters.size(); j++) {
            if (j == input.at(i).parameters.size() - 1) {
                std::cout << input.at(i).parameters.at(j)->paramString() << ")";
            }
            else {
                std::cout << input.at(i).parameters.at(j)->paramString() << ",";
            }
        }
        std::cout << std::endl;
    }
//    std::cout << std::endl;
}

Predicate::~Predicate() = default;
Predicate::Predicate() = default;

