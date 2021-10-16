#include "Rule.h"

void Rule::addBody(std::vector<Predicate *> input) {
    bodyPredicates = input;
}

void Rule::setHead(Predicate input) {
    headPredicate = &input;
    std::cout << headPredicate->id << std::endl;
}

void Rule::ruleString(Predicate *head, const std::vector<Predicate *>& body) {
    std::cout << head->id << std::endl;
    for (auto & parameter : head->parameters) {
        std::cout << parameter << std::endl;
    }
    for (auto & i : body) {
        std::cout << i->id << std::endl;
        for (auto & parameter : i->parameters) {
            std::cout << parameter << std::endl;
        }
    }

}

Rule::~Rule()= default;

Rule::Rule() = default;

