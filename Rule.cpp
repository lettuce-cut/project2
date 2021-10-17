#include "Rule.h"

void Rule::addBody(std::vector<Predicate> input) {
    bodyPredicates = input;
}

void Rule::setHead(const Predicate& input) {
    headPredicate.id = input.id;
    headPredicate.parameters = input.parameters;
}

void Rule::ruleString(std::vector<Rule> input) {
    for (auto & i : input) {
        std::cout << "  " << i.headPredicate.id << "(";
        for (long unsigned int j = 0; j < i.headPredicate.parameters.size(); j++) {
            if (j == i.headPredicate.parameters.size()-1) {
                std::cout << i.headPredicate.parameters.at(j)->paramString() << ")";
            }
            else {
                std::cout << i.headPredicate.parameters.at(j)->paramString() << ",";
            }
        }
        std::cout << " :- ";
        for (auto & bodyPredicate : i.bodyPredicates) {
            std::cout << bodyPredicate.id << "(";
            for (long unsigned int h = 0; h < bodyPredicate.parameters.size(); h++) {
                if (h == bodyPredicate.parameters.size()-1){
                    std::cout << bodyPredicate.parameters.at(h)->paramString() << ").";
                }
                else {
                    std::cout << bodyPredicate.parameters.at(h)->paramString() << ",";
                }
            }
        }
        std::cout << std::endl;
    }
//    std::cout << std::endl;
}


Rule::~Rule()= default;

Rule::Rule() = default;

