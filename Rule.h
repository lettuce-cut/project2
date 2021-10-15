#ifndef PROJECT_2_RULE_H
#define PROJECT_2_RULE_H

#include <vector>
#include <iostream>
#include "Predicate.h"

class Rule {
private:
    Predicate* headPredicate;
    std::vector<Predicate*> bodyPredicates;
public:
    Rule();
    ~Rule();
    void insertRule();
    void toString();
};

#endif //PROJECT_2_RULE_H
