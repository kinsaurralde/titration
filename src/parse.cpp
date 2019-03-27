#include <iostream>
#include <fstream>
#include "parse.h"
#include "sample.h"

Parser::Parser(int argc, char *argv[], Settings& settings) {
    parseString(sample[0]);
    int i = 1;
    while (i < argc - 1) {
        try {
            if (strcmp(argv[i], "-n") == 0) {
                changeNumCycles(argv[i + 1]);
            } else if (strcmp(argv[i], "-s") == 0) {
                changeSample(argv[i + 1]);
            } else if (strcmp(argv[i], "-t") == 0) {
                changeType(argv[i + 1]);
            } else if (strcmp(argv[i], "-ttv") == 0) {
                changeTitrantVol(argv[i + 1]);
            } else if (strcmp(argv[i], "-ttc") == 0) {
                changeTitrantConc(argv[i + 1]);
            } else if (strcmp(argv[i], "-tdv") == 0) {
                changeTitrandVol(argv[i + 1]);
            } else if (strcmp(argv[i], "-tdc") == 0) {
                changeTitrandConc(argv[i + 1]);
            } else if (strcmp(argv[i], "-f") == 0) {
                parseFile(argv[i + 1]);
            } else if (strcmp(argv[i], "-b") == 0) {
                settings.setPrint_to_stream(false);
                i--;
            }
        } catch (const std::invalid_argument &e) {
            std::cout << "Invalid argument: " << argv[i] << " " << argv[i + 1] << "  |  what: " << e.what()
                      << std::endl;
        } catch (...) {
            std::cout << "Invalid argument: " << argv[i] << " " << argv[i + 1] << std::endl;
        }
        i += 2;
    }
}

Parser::Parser(const char *input) {
    parseString(input);
}

std::map<std::string, std::string> Parser::getData() {
    return data;
}


void Parser::parseString(const char *input) {
    rapidjson::Document json;
    json.Parse(input);
    for (int i = 0; i < json.Capacity() * 2 - 1; i += 2) {
        std::cout << "Adding Value: " << json[i].GetString() << " = " << json[i + 1].GetString() << std::endl;
        data[json[i].GetString()] = json[i + 1].GetString();
    }
}

void Parser::parseFile(const char *path_to_file) {
    std::ifstream infile { path_to_file };
    std::string file_contents { std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };
    parseString(file_contents.c_str());
}

void Parser::changeNumCycles(std::string num) {
    if (stoi(num) > 0) {
        std::cout << "Changing number of cycles to: " << num << std::endl;
        data["num_cycles"] = num;
    } else {
        std::cout << "Number of cycles must be > 0: " << num << std::endl;
    }
}

void Parser::changeSample(std::string num) {
    int new_num = stoi(num);
    if (new_num >= 0 && new_num < 3) {
        parseString(sample[new_num]);
    } else {
        std::cout << "Preset sample not found: " << num << std::endl;
    }
}

void Parser::changeType(std::string type) {
    std::cout << "Changing type to: " << type << std::endl;
    data["type"] = type;
}

void Parser::changeTitrantVol(std::string num) {
    int new_num = stoi(num);
    if (new_num >= 0) {
        std::cout << "Changing titrant volume to: " << num << std::endl;
        data["titrant_vol"] = num;
    } else {
        std::cout << "Titrant volume must be >= 0" << std::endl;
    }
}

void Parser::changeTitrantConc(std::string num) {
    int new_num = stoi(num);
    if (new_num >= 0) {
        std::cout << "Changing titrant concentration to: " << num << std::endl;
        data["titrant_conc"] = num;
    } else {
        std::cout << "Titrant concentration must be >= 0" << std::endl;
    }
}

void Parser::changeTitrandVol(std::string num) {
    int new_num = stoi(num);
    if (new_num >= 0) {
        std::cout << "Changing titrand volume to: " << num << std::endl;
        data["titrand_vol"] = num;
    } else {
        std::cout << "Titrand volume must be >= 0" << std::endl;
    }
}

void Parser::changeTitrandConc(std::string num) {
    int new_num = stoi(num);
    if (new_num >= 0) {
        std::cout << "Changing titrand concentration to: " << num << std::endl;
        data["titrand_conc"] = num;
    } else {
        std::cout << "Titrand concentration must be >= 0" << std::endl;
    }
}
