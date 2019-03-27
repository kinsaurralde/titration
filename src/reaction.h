#ifndef TITRATION_REACTION_H
#define TITRATION_REACTION_H

#include <iostream>
#include <memory>
#include <map>

#include "component.h"
#include "view.h"

class View;

class Reaction {
public:
    friend Component;
    Reaction(std::map<std::string, std::string> input_data, View *view);

    virtual void setup() = 0;

    virtual void run() = 0;

    virtual void calculatePH() = 0;

    virtual void addTitrant(double moles_added, double volume_added) = 0;

    double getPH();

    double getPOH();

    double getConcH();

    double getConcOH();

    void printCurrentData();

    View *getView() const;

    const std::unique_ptr<Component> &getAcid() const;

    const std::unique_ptr<Component> &getBase() const;

    double getTotal_volume() const;


protected:
    std::map<std::string, std::string> input_data;
    std::unique_ptr<Component> acid;
    std::unique_ptr<Component> base;
    View* view;
    double titrant_vol;
    double titrant_conc;
    double titrant_mol;
    double total_volume;
    bool titrant_is_acid;
    double pH;
    int num_cycles;
};

#endif //TITRATION_REACTION_H
