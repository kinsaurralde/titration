#include "controller.h"
#include "StrongAcidBase.h"

Controller::Controller(std::map<std::string, std::string> input) : is_setup(false) , error(false) , input_data(input){
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
        error = true;
        error_message = "Invalid type given";
    }
    std::cout << "Setting up titration of type " << type << std::endl;
}

void Controller::setupReaction() {
    if (!error) {
        switch (type) {
            case SASB:
                reaction = std::make_unique<StrongAcidBase>(StrongAcidBase(input_data, type));
                break;
            case SBSA:
                break;
            case SAWB:
                break;
            case SBWA:
                break;
            case NONE:
                break;
        }
        is_setup = true;
    }
}

void Controller::run() {
    reaction->run();
}