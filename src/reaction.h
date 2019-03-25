#ifndef TITRATION_REACTION_H
#define TITRATION_REACTION_H

#include <iostream>
#include <memory>
#include <map>

#include "component.h"

class Reaction {
public:
    Reaction(std::map<std::string, std::string> input_data);

    virtual void setup() = 0;

    virtual void run() = 0;

    virtual void calculatePH() = 0;

    double getPH();

    double getPOH();

    double getConcH();

    double getConcOH();

    void printCurrentData();


protected:
    std::map<std::string, std::string> input_data;
    std::unique_ptr<Component> acid;
    std::unique_ptr<Component> base;
    double titrant_vol;
    double titrant_conc;
    bool titrant_is_acid;
    double pH;
};

#endif //TITRATION_REACTION_H
