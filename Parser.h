#ifndef PROJECT_2_PARSER_H
#define PROJECT_2_PARSER_H

#include <vector>
#include <iostream>
#include "Lexer.h"
class Parser {
private:
    void datalogProgramParse();
    void schemeListPars();
    void factListParse();
    void ruleListParse();
    void queryListParse();
    void schemeParse();
    void factParse();
    void ruleParse();
    void queryParse();
    void headPredicateParse();
    void predicateParse();
    void predicateListParse();
    void parameterList();
    void stringList();
    void idListParse();
    void parameterParse();
public:
    Parser();
    ~Parser();

    void parseRun(std::vector<Token*> toParse);
//    void productionMatch(const std::string& input);
};


#endif //PROJECT_2_PARSER_H
