#include "Rule.h"

void Rule::addBody(std::vector<Predicate *> input) {
    bodyPredicates = input;
}

void Rule::setHead(Predicate input) {
    headPredicate = &input;
//    std::cout << headPredicate->id << std::endl;
}

void Rule::ruleString(Predicate *head, std::vector<Predicate *> body) {
    std::cout << head->id << std::endl;
    for (int i = 0; i < head->parameters.size(); i++) {
        std::cout << head->parameters.at(i) << std::endl;
    }
    for (int i = 0; i < body.size(); i++) {
        std::cout << body.at(i)->id << std::endl;
        for (int j = 0; j < body.at(i)->parameters.size(); j++) {
            std::cout << body.at(i)->parameters.at(j) << std::endl;
        }
    }

}

Rule::~Rule(){

}

Rule::Rule() {

}

