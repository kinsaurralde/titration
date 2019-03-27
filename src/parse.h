#ifndef TITRATION_PARSE_H
#define TITRATION_PARSE_H

#include <map>
#include "../include/rapidjson/document.h"
#include "settings.h"

class Parser {
public:
    explicit Parser(const char *input);

    Parser(int argc, char *argv[], Settings& settings);

    void parseString(const char *input);

    void parseFile(const char* path_to_file);

    void changeNumCycles(std::string num);

    void changeSample(std::string num);

    void changeType(std::string type);

    void changeTitrantVol(std::string num);

    void changeTitrantConc(std::string num);

    void changeTitrandVol(std::string num);

    void changeTitrandConc(std::string num);

    std::map<std::string, std::string> getData();

protected:
    std::map<std::string, std::string> data;
};

#endif  // TITRATION_PARSE_H
