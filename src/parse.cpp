#include <iostream>
#include "parse.h"
#include "../include/rapidjson/document.h"

Parser::Parser(const char* input) {
    rapidjson::Document json;
    json.Parse(input);
    for (int i = 0; i < json.Capacity() * 2 - 1; i += 2) {
        std::cout << "Adding Value: " << json[i].GetString() << " = " << json[i+1].GetString() << std::endl;
        data[json[i].GetString()] = json[i+1].GetString();
    }
}

std::map<std::string, std::string> Parser::getData() {
    return data;
}

