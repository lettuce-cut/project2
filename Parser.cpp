//
// Created by Sailor Ong on 10/5/21.
//

#include "Parser.h"
#include "Token.h"


void Parser::parseRun(std::vector<Token*> toParse) {
    std::cout << std::endl << "In parser" << std::endl;

    std::cout << toParse.size() << std::endl;
    for (int i = 0; i < toParse.size(); i++) {
        std::cout << toParse.size() << std::endl;
        std::cout << toParse[i] << std::endl;
    }
}

Parser::Parser() {

}

Parser::~Parser() {

}

