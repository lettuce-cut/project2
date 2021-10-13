#ifndef PROJECT_2_PARSER_H
#define PROJECT_2_PARSER_H

#include <vector>
#include <iostream>
#include "Lexer.h"
class Parser {
private:
    int index = 0;
    void datalogProgramParse(std::vector<Token*> toParse);
    void schemeListPars(std::vector<Token*> toParse);
    void factListParse(std::vector<Token*> toParse);
    void ruleListParse(std::vector<Token*> toParse);
    void queryListParse(std::vector<Token*> toParse);
    void schemeParse(std::vector<Token*> toParse);
    void factParse(std::vector<Token*> toParse);
    void ruleParse(std::vector<Token*> toParse);
    void queryParse(std::vector<Token*> toParse);
    void headPredicateParse(std::vector<Token*> toParse);
    void predicateParse(std::vector<Token*> toParse);
    void predicateListParse(std::vector<Token*> toParse);
    void parameterList(std::vector<Token*> toParse);
    void stringList(std::vector<Token*> toParse);
    void idListParse(std::vector<Token*> toParse);
    void parameterParse(std::vector<Token*> toParse);
    void Match(Token *pToken, TokenType);
public:
    Parser();
    ~Parser();

    void parseRun(std::vector<Token*> toParse);
};


#endif //PROJECT_2_PARSER_H
