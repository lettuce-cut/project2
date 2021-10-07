//
// Created by Sailor Ong on 10/5/21.
//

#include "Parser.h"
#include "Token.h"


void Parser::parseRun(std::vector<Token*> toParse) {
    std::cout << std::endl << "In parser" << std::endl;
    std::string productionMatch = "ERROR";
    for (int i = 0; i < toParse.size(); ++i) {
        if (toParse[i]->getType() == "SCHEMES") {
            std::cout << "True" << std::endl;
        }
        else {
            std::cout <<"False" << std::endl;
        }
    }
}

Parser::Parser() {

}

Parser::~Parser() {

}

//void Parser::productionMatch(const std::string & input) {
//
//}
