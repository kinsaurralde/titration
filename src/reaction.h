#ifndef TITRATION_REACTION_H
#define TITRATION_REACTION_H

#include <iostream>
#include <map>

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
    double pH;
    double init_acid_conc;
    double init_base_conc;
    double init_acid_vol;
    double init_base_vol;
    double acid_conc;
    double base_conc;
    double acid_vol;
    double base_vol;
};

#endif //TITRATION_REACTION_H
