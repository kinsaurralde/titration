#include "reaction.h"
#include <math.h>

Reaction::Reaction(std::map<std::string, std::string> input_data, View *view) : input_data(std::move(input_data)),
                                                                                pH(0), view(view) {};

double Reaction::getPH() {
    calculatePH();
    return pH;
}

double Reaction::getPOH() {
    return 14 - getPH();
}

double Reaction::getConcH() {
    return pow(10, -getPH());
}

double Reaction::getConcOH() {
    return pow(10, -getPOH());
}

void Reaction::printCurrentData() {
    std::cout << " pH: " << getPH();
    std::cout << " Acid Concentration: " << acid->getConcentration();
    std::cout << " Acid Moles: " << acid->getMoles();
    std::cout << " Acid Volume: " << acid->getVolume();
    std::cout << " Base Concentration: " << base->getConcentration();
    std::cout << " Base Moles: " << base->getMoles();
    std::cout << " Base Volume: " << base->getVolume() << std::endl;
}

const std::unique_ptr<Component> &Reaction::getAcid() const {
    return acid;
}

const std::unique_ptr<Component> &Reaction::getBase() const {
    return base;
}

double Reaction::getTotal_volume() const {
    return total_volume;
}
