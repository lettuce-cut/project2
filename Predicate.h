#ifndef PROJECT_2_PREDICATE_H
#define PROJECT_2_PREDICATE_H

#include <vector>
#include <iostream>
#include "Parameter.h"
#include "Token.h"

class Predicate {
private:
    std::vector<Parameter*> parameters;
public:
    Predicate(Token *input);
    Predicate();
    ~Predicate();
    void toString();
    void addParameter(std::vector<Parameter*> input);

    std::string id;
};

#endif //PROJECT_2_PREDICATE_H
