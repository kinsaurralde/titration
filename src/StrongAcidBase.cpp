#include "StrongAcidBase.h"
#include <math.h>


StrongAcidBase::StrongAcidBase(std::map<std::string, std::string> input_data, int type) : Reaction(
        std::move(input_data)), type(type) {
    setup();
}

void StrongAcidBase::setup() {
    int num_values = 0;
    double titrant_conc = 0;
    double titrant_vol = 0;
    double titrand_conc = 0;
    double titrand_vol = 0;
    if (input_data.count("titrant_conc") == 1) {
        titrant_conc = stod(input_data.at("titrant_conc"));
        num_values++;
    }
    if (input_data.count("titrant_vol") == 1) {
        titrant_vol = stod(input_data.at("titrant_vol"));
        num_values++;
    }
    if (input_data.count("titrand_conc") == 1) {
        titrand_conc = stod(input_data.at("titrand_conc"));
        num_values++;
    }
    if (input_data.count("titrand_vol") == 1) {
        titrand_vol = stod(input_data.at("titrand_vol"));
        num_values++;
    }
    if (num_values != 4) {
        throw std::logic_error("Not all initial values found");
    }
    if (type == 1) {    // SASB
        init_acid_conc = titrant_conc;
        init_acid_vol = titrant_vol;
        init_base_conc = titrand_conc;
        init_base_vol = titrand_vol;
    } else if (type == 2) { //SBSA
        init_acid_conc = titrand_conc;
        init_acid_vol = titrand_vol;
        init_base_conc = titrant_conc;
        init_base_vol = titrant_vol;
    } else {
        std::cout << "Invalid type given to StrongAcidBase";
        throw "Invalid type given to StrongAcidBase";
    }
    acid_conc = init_acid_conc;
    acid_vol = init_acid_vol;
    base_conc = init_base_conc;
    base_vol = init_base_vol;
}

void StrongAcidBase::run() {

}

void StrongAcidBase::calculatePH() {
    pH = -log10(acid_conc);
}
