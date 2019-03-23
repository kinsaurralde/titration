#include "controller.h"

Controller::Controller(std::map<std::string, std::string> input) {
    // std::cout << input.at("titrant_conc") << std::endl;
    std::string type_name = input.at("type");
    if (type_name == "SASB") {
        type = SASB;
    } else if (type_name == "SBSA") {
        type = SBSA;
    } else if (type_name == "SAWB") {
        type = SAWB;
    } else if (type_name == "SBWA") {
        type = SAWB;
    } else {
        type = NONE;
    }
    std::cout << "Setting up titration of type " << type << std::endl;
}

void Controller::setup() {}

void Controller::run() {}