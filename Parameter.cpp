#include "Parameter.h"

Parameter::Parameter(std::string input) {
    p = input;
//    std::cout<< p << std::endl;
}

void Parameter::paramString(Parameter input) {
    std::cout << input.p << std::endl;
}