#include "DatalogProgram.h"
#include "Token.h"
#include "Predicate.h"

std::vector<Parameter*> toPass;

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
    Match(toParse.at(index), TokenType::END); //Make an END function with all the correct output
}
void DatalogProgram::schemeListPars(const std::vector<Token*>& toParse) {
//    if (toParse.at(index)->type != TokenType::FACTS) {
//        Match(toParse.at(index), TokenType::FACTS);
//    }
    if (toParse.at(index)->type == TokenType::ID) {
        schemeParse(toParse);
        schemeListPars(toParse);
        pSchemes.addParameter(toPass);
        toPass.clear();
    }
}
void DatalogProgram::factListParse(const std::vector<Token*>& toParse) {
    if (toParse.at(index)->type == TokenType::ID) {
        factParse(toParse);
        factListParse(toParse);
        pSchemes.addParameter(toPass);
        toPass.clear();
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
        pQueries.addParameter(toPass);
        toPass.clear();
    }
}
void DatalogProgram::schemeParse(std::vector<Token*> toParse) {
    pSchemes.id = toParse.at(index)->value;
    std::cout << pSchemes.id << std::endl;
    Match(toParse.at(index), TokenType::ID);
    Match(toParse.at(index), TokenType::LEFT_PAREN);
    Match(toParse.at(index), TokenType::ID);
    toPass.push_back(new Parameter(toParse.at(index-1)->value));
    idListParse(toParse);
    Match(toParse.at(index), TokenType::RIGHT_PAREN);
}

void DatalogProgram::factParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::ID);
    pFacts.id = toParse.at(index-1)->value;
    std::cout << pFacts.id << std::endl;
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
    pQueries.id = toParse.at(index)->value;
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
//    new Predicate(toParse.at(index));
    Match(toParse.at(index), TokenType::ID);
    toPass.push_back(new Parameter(toParse.at(index-1)->value));
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
        toPass.push_back(new Parameter(toParse.at(index-1)->value));//stored
        stringList(toParse);
    }
}
void DatalogProgram::idListParse(std::vector<Token*> toParse) {
    if (toParse.at(index)->type == TokenType::COMMA) {
        Match(toParse.at(index), TokenType::COMMA);
        Match(toParse.at(index), TokenType::ID);
        toPass.push_back(new Parameter(toParse.at(index-1)->value));
        idListParse(toParse);

    }
}
void DatalogProgram::parameterParse(std::vector<Token*> toParse) {
    if (toParse.at(index)->type != TokenType::END) {

        if (toParse.at(index)->type == TokenType::STRING) {
            Match(toParse.at(index), TokenType::STRING);
            toPass.push_back(new Parameter(toParse.at(index-1)->value));//stored
        } else {
            Match(toParse.at(index), TokenType::ID);
            toPass.push_back(new Parameter(toParse.at(index-1)->value));//stored
        }
    }
}

DatalogProgram::DatalogProgram()= default;

DatalogProgram::~DatalogProgram()= default;
