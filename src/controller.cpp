#include "controller.h"
#include "StrongAcidBase.h"
#include "StandardView.h"
#include "AWSView.h"
#include "settings.h"

Controller::Controller(std::map<std::string, std::string> input, Settings &settings)
        : is_setup(false) , error(false) , input_data(input) ,  settings(settings) {
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

void Controller::applySettings() {
    if (settings.isAws_version()) {
        view = std::make_unique<AWSView>(*this, settings.getStream());
    } else {
        view = std::make_unique<StandardView>(*this, settings.getStream());
    }
}

void Controller::setupReaction() {
    if (!error) {
        switch (type) {
            case SASB:
                reaction = std::make_unique<StrongAcidBase>(StrongAcidBase(input_data, type, view.get()));
                break;
            case SBSA:
                reaction = std::make_unique<StrongAcidBase>(StrongAcidBase(input_data, type, view.get()));
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
    reaction->getView()->printFile();
    if (settings.isPrint_to_csv()) {
        reaction->getView()->printCSV();
    }
    if (settings.isPrint_to_stream()) {
        reaction->getView()->printScreen();
    }
}

const std::unique_ptr<Reaction> &Controller::getReaction() const {
    return reaction;
}

Settings &Controller::getSettings() const {
    return settings;
}
