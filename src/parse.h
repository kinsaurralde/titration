#ifndef TITRATION_PARSE_H
#define TITRATION_PARSE_H

#include <map>

class Parser {
   public:
    Parser(const char* input);
    std::map<std::string, std::string> getData();

   protected:
    std::map<std::string, std::string> data;
};

#endif  // TITRATION_PARSE_H
