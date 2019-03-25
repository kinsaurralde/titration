#include "StrongAcidBase.h"
#include <math.h>


StrongAcidBase::StrongAcidBase(std::map<std::string, std::string> input_data, int type) : Reaction(
        std::move(input_data)), type(type) {
    setup();
}

void StrongAcidBase::setup() {
    double titrand_conc = 0;
    double titrand_vol = 0;
    try {
        titrant_conc = stod(input_data.at("titrant_conc"));
        titrant_vol = stod(input_data.at("titrant_vol"));
        titrand_conc = stod(input_data.at("titrand_conc"));
        titrand_vol = stod(input_data.at("titrand_vol"));
    } catch (char* e) {
        std::cout << "Missing parameters" << std::endl;
        std::cout << "Message: " << e << std::endl;
        exit(1);
    }
    if (type == 1) {    // SASB
        titrant_is_acid = false;
        base = std::make_unique<Component>(Component());
        acid = std::make_unique<Component>(Component(titrand_conc, titrand_vol));
    } else if (type == 2) { //SBSA
        titrant_is_acid = true;
        acid = std::make_unique<Component>(Component());
        base = std::make_unique<Component>(Component(titrand_conc, titrand_vol));
    } else {
        std::cout << "Invalid type given to StrongAcidBase";
        throw "Invalid type given to StrongAcidBase";
    }

}

void StrongAcidBase::run() {

}

void StrongAcidBase::calculatePH() {
    pH = -log10(acid->getConcentration());
}
