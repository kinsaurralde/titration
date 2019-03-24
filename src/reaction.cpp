#include "reaction.h"
#include <math.h>

Reaction::Reaction(std::map<std::string, std::string> input_data) : input_data(std::move(input_data)) , pH(0) {

}

double Reaction::getPH() {
    calculatePH();
    return pH;
}

double Reaction::getPOH() {
    return 14-getPH();
}

double Reaction::getConcH() {
    return pow(10, -getPH());
}

double Reaction::getConcOH() {
    return pow(10, -getPOH());
}

void Reaction::printCurrentData() {
    std::cout << "Current Data" << std::endl;
    std::cout << "pH: " << getPH() << std::endl;
    std::cout << "Acid Concentration: " << acid_conc << std::endl;
    std::cout << "Acid Volume: " << acid_vol << std::endl;
    std::cout << "Base Concentration: " << base_conc << std::endl;
    std::cout << "Base Volume: " << base_vol << std::endl;
}
