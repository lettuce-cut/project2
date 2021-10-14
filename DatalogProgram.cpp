//
// Created by Sailor Ong on 10/5/21.
//

#include "DatalogProgram.h"
#include "Token.h"


void DatalogProgram::parseRun(const std::vector<Token*>& toParse) {
//    std::cout << std::endl << "In parser" << std::endl;
//    for (int i = 0; i < toParse.size(); i++){
//        std::cout << toParse[i]->toString() << std::endl;
//    }
//    Match(toParse.at(index), TokenType::SCHEMES);
//    Match(toParse.at(index), TokenType::COLON);
    datalogProgramParse(toParse);
}
void DatalogProgram::Match(Token *pToken, TokenType tokenType) {
//    std::cout << "In Match" << std::endl;
    if (pToken->type == tokenType) {
//        std::cout << "In Match equal" << std::endl;
        index++;
    }

    else {
//        std::cout << "In Match else" << std::endl;
        std::string error = pToken->toString();
        throw error;
    }
}

void DatalogProgram::datalogProgramParse(std::vector<Token*> toParse) {
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
    Match(toParse.at(index), TokenType::END); //Make and END function with all the correct output
}
void DatalogProgram::schemeListPars(const std::vector<Token*>& toParse) {
//    if (toParse.at(index)->type != TokenType::FACTS) {
//        Match(toParse.at(index), TokenType::FACTS);
//    }
    if (toParse.at(index)->type == TokenType::ID) {
        schemeParse(toParse);
        schemeListPars(toParse);
    }
}
void DatalogProgram::factListParse(const std::vector<Token*>& toParse) {
    if (toParse.at(index)->type == TokenType::ID) {
        factParse(toParse);
        factListParse(toParse);
    }
}
void DatalogProgram::ruleListParse(const std::vector<Token*>& toParse) {
    if (toParse.at(index)->type == TokenType::ID) {
        ruleParse(toParse);
        ruleListParse(toParse);
    }
}
void DatalogProgram::queryListParse(const std::vector<Token*>& toParse) {
    if (toParse.at(index)->type == TokenType::ID) {
        queryParse(toParse);
        queryListParse(toParse);
    }
}
void DatalogProgram::schemeParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::ID);
    Match(toParse.at(index), TokenType::LEFT_PAREN);
    Match(toParse.at(index), TokenType::ID);
    idListParse(toParse);
    Match(toParse.at(index), TokenType::RIGHT_PAREN);
}
void DatalogProgram::factParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::ID);
    Match(toParse.at(index), TokenType::LEFT_PAREN);
    Match(toParse.at(index), TokenType::STRING);
    stringList(toParse);
    Match(toParse.at(index), TokenType::RIGHT_PAREN);
    Match(toParse.at(index), TokenType::PERIOD);
}
void DatalogProgram::ruleParse(std::vector<Token*> toParse) {
    headPredicateParse(toParse);
    Match(toParse.at(index), TokenType::COLON_DASH);
    predicateParse(toParse);
    predicateListParse(toParse);
    Match(toParse.at(index), TokenType::PERIOD);
}
void DatalogProgram::queryParse(std::vector<Token*> toParse) {
    predicateParse(toParse);
    Match(toParse.at(index), TokenType::QMARK);
}
void DatalogProgram::headPredicateParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::ID);
    Match(toParse.at(index), TokenType::LEFT_PAREN);
    Match(toParse.at(index), TokenType::ID);
    idListParse(toParse);
    Match(toParse.at(index), TokenType::RIGHT_PAREN);
}
void DatalogProgram::predicateParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::ID);
    Match(toParse.at(index), TokenType::LEFT_PAREN);
    parameterParse(toParse);
    parameterList(toParse);
    Match(toParse.at(index), TokenType::RIGHT_PAREN);
}
void DatalogProgram::predicateListParse(std::vector<Token*> toParse) {
    if (toParse.at(index)->type == TokenType::COMMA) {
        Match(toParse.at(index), TokenType::COMMA);
        predicateParse(toParse);
        predicateListParse(toParse);
    }
}
void DatalogProgram:: parameterList(std::vector<Token*> toParse) {
    if (toParse.at(index)->type == TokenType::COMMA) {
        Match(toParse.at(index), TokenType::COMMA);
        parameterParse(toParse);
        parameterList(toParse);
    }
}
void DatalogProgram::stringList(std::vector<Token*> toParse) {
    if (toParse.at(index)->type == TokenType::COMMA) {
        Match(toParse.at(index), TokenType::COMMA);
        Match(toParse.at(index), TokenType::STRING);
        stringList(toParse);
    }
}
void DatalogProgram::idListParse(std::vector<Token*> toParse) {
    if (toParse.at(index)->type == TokenType::COMMA) {
        Match(toParse.at(index), TokenType::COMMA);
        Match(toParse.at(index), TokenType::ID);
        idListParse(toParse);
    }
}
void DatalogProgram::parameterParse(std::vector<Token*> toParse) {
    if (toParse.at(index)->type != TokenType::END) {
        if (toParse.at(index)->type == TokenType::STRING) {
            Match(toParse.at(index), TokenType::STRING);
        } else {
            Match(toParse.at(index), TokenType::ID);
        }
    }
}

DatalogProgram::DatalogProgram() = default;

DatalogProgram::~DatalogProgram() = default;
