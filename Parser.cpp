//
// Created by Sailor Ong on 10/5/21.
//

#include "Parser.h"
#include "Token.h"


//void Parser::parseRun(std::vector<Token*> toParse) {
//    std::cout << std::endl << "In parser" << std::endl;
//    std::cout << toParse.size() << std::endl;
//    for (int i = 0; i < toParse.size(); i++) {
//        std::cout << toParse[i]->getType() << std::endl;
//        parseMatch(toParse[i]->getType() )
//
//}
void Parser::Match(Token *pToken, TokenType) {
    if (TokenType() == pToken->type) {
        throw ("Error");
    } else {
        index++;
    }
}

void Parser::datalogProgramParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::SCHEMES);
    Match(toParse.at(index), TokenType::COLON);
    schemeParse(toParse);
    schemeListPars(toParse);
    Match(toParse.at(index), TokenType::FACTS);
    Match(toParse.at(index), TokenType::COLON);
    factListParse(toParse);
    Match(toParse.at(index), TokenType::RULES);
    Match(toParse.at(index), TokenType::COLON);
    ruleListParse(toParse);
    Match(toParse.at(index), TokenType::QUERIES);
    Match(toParse.at(index), TokenType::COLON);
    queryParse(toParse);
    queryListParse(toParse);
    Match(toParse.at(index), TokenType::EOF);
}
void Parser::schemeListPars(std::vector<Token*> toParse) {

}
void Parser::factListParse(std::vector<Token*> toParse) {

}
void Parser::ruleListParse(std::vector<Token*> toParse) {

}
void Parser::queryListParse(std::vector<Token*> toParse) {
    if (queryParse(toParse)) {
        queryParse(toParse);
        queryListParse(toParse);
    }
}
void Parser::schemeParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::ID);
    Match(toParse.at(index), TokenType::LEFT_PAREN);
    Match(toParse.at(index), TokenType::ID);
    idListParse(toParse);
    Match(toParse.at(index), TokenType::RIGHT_PAREN);
}
void Parser::factParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::ID);
    Match(toParse.at(index), TokenType::LEFT_PAREN);
    Match(toParse.at(index), TokenType::STRING);
    stringList(toParse);
    Match(toParse.at(index), TokenType::RIGHT_PAREN);
    Match(toParse.at(index), TokenType::PERIOD);
}
void Parser::ruleParse(std::vector<Token*> toParse) {
    headPredicateParse(toParse);
    Match(toParse.at(index), TokenType::COLON_DASH);
    predicateParse(toParse);
    predicateListParse(toParse);
    Match(toParse.at(index), TokenType::PERIOD);
}
void Parser::queryParse(std::vector<Token*> toParse) {
    predicateParse(toParse);
    Match(toParse.at(index), TokenType::QMARK);
}
void Parser::headPredicateParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::ID);
    Match(toParse.at(index), TokenType::LEFT_PAREN);
    Match(toParse.at(index), TokenType::ID);
    idListParse(toParse);
    Match(toParse.at(index), TokenType::RIGHT_PAREN);
}
void Parser::predicateParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::ID);
    Match(toParse.at(index), TokenType::LEFT_PAREN);
    parameterParse(toParse);
    parameterList(toParse);
    Match(toParse.at(index), TokenType::RIGHT_PAREN);
}
void Parser::predicateListParse(std::vector<Token*> toParse) {
    if (toParse.at(index)->type == TokenType::COMMA) {
        predicateParse(toParse);
        predicateListParse(toParse);
    }
}
void Parser:: parameterList(std::vector<Token*> toParse) {
    if (toParse.at(index)->type == TokenType::COMMA) {
        parameterParse(toParse);
        parameterList(toParse);
    }
}
void Parser::stringList(std::vector<Token*> toParse) {
    if (toParse.at(index)->type == TokenType::COMMA) {
        Match(toParse.at(index), TokenType::COMMA);
        Match(toParse.at(index), TokenType::STRING);
        stringList(toParse);
    }
}
void Parser::idListParse(std::vector<Token*> toParse) {
    if (toParse.at(index)->type == TokenType::COMMA) {
        Match(toParse.at(index), TokenType::COMMA);
        Match(toParse.at(index), TokenType::ID);
        idListParse(toParse);
    }
}
void Parser::parameterParse(std::vector<Token*> toParse) {
    if (toParse.at(index)->type == TokenType::STRING) {
        Match(toParse.at(index), TokenType::STRING);
    }
    else {
        Match(toParse.at(index), TokenType::ID);
    }
}

Parser::Parser() {
}

Parser::~Parser() {
}
