#ifndef PROJECT_2_PREDICATE_H
#define PROJECT_2_PREDICATE_H

#include <vector>
#include <iostream>
#include "Parameter.h"
#include "Token.h"

class Predicate {
public:
    Predicate(Token *input);
//    Predicate();
    Predicate(std::string name) { this->id = name; }
    ~Predicate();
    void predicateString(Predicate input);
    void addParameter(std::vector<Parameter*> input);

    std::string id;

    Predicate();

    std::vector<Parameter*> parameters;
};

#endif //PROJECT_2_PREDICATE_H
