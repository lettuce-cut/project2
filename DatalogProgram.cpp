#include "DatalogProgram.h"
#include "Token.h"
#include "Predicate.h"

std::vector<Parameter*> toPass;
std::vector<Predicate*> toPassPred;
std::vector<Predicate> vectorSchemes;
std::vector<Predicate> vectorQueries;
std::vector<Predicate> vectorFacts;

Predicate pSchemes;
Predicate pQueries;
Predicate pFacts;
Rule rRules;
Predicate pRulesHead;


void DatalogProgram::parseRun(const std::vector<Token*>& toParse) {
//    Match(toParse.at(index), TokenType::SCHEMES);
//    Match(toParse.at(index), TokenType::COLON);
    datalogProgramParse(toParse);
}
void DatalogProgram::Match(Token *pToken, TokenType tokenType) {
    if (pToken->type == tokenType) {
        index++;
    }
    else {
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
    vectorSchemes.push_back(pSchemes);
    std::cout << "Vector size: " << vectorSchemes.size() << std::endl;
    if (toParse.at(index)->type == TokenType::ID) {
        std::cout << "in schemeList parse" << std::endl;
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

        pFacts.addParameter(toPass);
        vectorFacts.push_back(pFacts);
        toPass.clear();
    }
}
void DatalogProgram::ruleListParse(const std::vector<Token*>& toParse) {
    if (toParse.at(index)->type == TokenType::ID) {
        ruleParse(toParse);
        ruleListParse(toParse);

        rRules.addBody(toPassPred);

        toPassPred.clear();
    }
}
void DatalogProgram::queryListParse(const std::vector<Token*>& toParse) {
    if (toParse.at(index)->type == TokenType::ID) {
        queryParse(toParse);
        queryListParse(toParse);

        pQueries.addParameter(toPass);
        vectorQueries.push_back(pQueries);
        toPass.clear();
    }
}
void DatalogProgram::schemeParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::ID);
    pSchemes.id = toParse.at(index-1)->value;
//    std::cout << pSchemes.id << std::endl;
    Match(toParse.at(index), TokenType::LEFT_PAREN);
    Match(toParse.at(index), TokenType::ID);
    toPass.push_back(new Parameter(toParse.at(index-1)->value));//stored
    idListParse(toParse);
    Match(toParse.at(index), TokenType::RIGHT_PAREN);
}

void DatalogProgram::factParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::ID);
    pFacts.id = toParse.at(index-1)->value;
//    std::cout << pFacts.id << std::endl;
    Match(toParse.at(index), TokenType::LEFT_PAREN);
    Match(toParse.at(index), TokenType::STRING);
    toPass.push_back(new Parameter(toParse.at(index-1)->value));//stored
    stringList(toParse);
    Match(toParse.at(index), TokenType::RIGHT_PAREN);
    Match(toParse.at(index), TokenType::PERIOD);
}

//Work on this Function
void DatalogProgram::ruleParse(std::vector<Token*> toParse) {
    headPredicateParse(toParse);
    pRulesHead.addParameter(toPass);
    Rule().setHead(pRulesHead);
    toPass.clear();

    Match(toParse.at(index), TokenType::COLON_DASH);
    predicateParse(toParse);
    predicateListParse(toParse);
    Match(toParse.at(index), TokenType::PERIOD);
}



void DatalogProgram::queryParse(std::vector<Token*> toParse) {
    pQueries.id = toParse.at(index)->value;
//    std::cout << pQueries.id << std::endl;
    predicateParse(toParse);
    Match(toParse.at(index), TokenType::QMARK);
}


//Work on this function
void DatalogProgram::headPredicateParse(std::vector<Token*> toParse) {
    Match(toParse.at(index), TokenType::ID);
    pRulesHead.id = toParse.at(index-1)->value;
//    std::cout << pRulesHead.id << std::endl;
    Match(toParse.at(index), TokenType::LEFT_PAREN);
    Match(toParse.at(index), TokenType::ID);
    toPass.push_back(new Parameter(toParse.at(index-1)->value));
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


//Work on this function
void DatalogProgram::predicateListParse(std::vector<Token*> toParse) {
    if (toParse.at(index)->type == TokenType::COMMA) {
        Match(toParse.at(index), TokenType::COMMA);
        predicateParse(toParse);
        predicateListParse(toParse);
        toPassPred.push_back(new Predicate(toParse.at(index)));
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
            toPass.push_back(new Parameter(toParse.at(index - 1)->value));//stored
        } else {
            Match(toParse.at(index), TokenType::ID);
            toPass.push_back(new Parameter(toParse.at(index - 1)->value));//stored
        }
    }
}

void DatalogProgram::outputString(){
    std::cout << "In output string" << std::endl;
    Predicate::stringPredicate(vectorSchemes);
}

DatalogProgram::DatalogProgram() = default;

DatalogProgram::~DatalogProgram()= default;
