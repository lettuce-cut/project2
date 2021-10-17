#include "Parameter.h"

Parameter::Parameter(std::string input) {
    p = input;
//    std::cout<< p << std::endl;
}

std::string Parameter::paramString() {
    return p;
}

Parameter::~Parameter() {

}
