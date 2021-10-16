#ifndef PROJECT_2_PARAMETER_H
#define PROJECT_2_PARAMETER_H

#include <vector>
#include <iostream>

class Parameter {
private:
    std::string p;
public:
    Parameter(std::string input);
    ~Parameter();
    static void paramString(const Parameter& input);
};

#endif //PROJECT_2_PARAMETER_H
