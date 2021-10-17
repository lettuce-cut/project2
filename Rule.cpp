#include "Rule.h"

void Rule::addBody(std::vector<Predicate> input) {
    bodyPredicates = input;
}

void Rule::setHead(Predicate input) {
    headPredicate.id = input.id;
    headPredicate.parameters = input.parameters;
}

void Rule::ruleString(std::vector<Rule> input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << "  " << input.at(i).headPredicate.id << "(";
        for (int j = 0; j < input.at(i).headPredicate.parameters.size(); j++) {
            if (j == input.at(i).headPredicate.parameters.size()-1) {
                std::cout << input.at(i).headPredicate.parameters.at(j)->paramString() << ")";
            }
            else {
                std::cout << input.at(i).headPredicate.parameters.at(j)->paramString() << ",";
            }
        }
        std::cout << " :- ";
        for (int k = 0; k < input.at(i).bodyPredicates.size(); k++) {
            std::cout << input.at(i).bodyPredicates.at(k).id << "(";
            for (int h = 0; h < input.at(i).bodyPredicates.at(k).parameters.size(); h++) {
                if (h == input.at(i).bodyPredicates.at(k).parameters.size()-1){
                    std::cout << input.at(i).bodyPredicates.at(k).parameters.at(h)->paramString() << ")";
                }
                else {
                    std::cout << input.at(i).bodyPredicates.at(k).parameters.at(h)->paramString() << ",";
                }
            }
        }
        std::cout << std::endl;
    }
//    std::cout << std::endl;
}


Rule::~Rule()= default;

Rule::Rule() = default;

