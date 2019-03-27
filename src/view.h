#ifndef TITRATION_VIEW_H
#define TITRATION_VIEW_H

#include "controller.h"

class Controller;

class View {
public:
    View(Controller& control);

    virtual void printCurrentStep() = 0;

    virtual void printCurrentStep(int i, double moles_added, double volume_added) = 0;

    virtual void printScreen();

    virtual void printFile() = 0;

    virtual void printCSV();

    virtual void print(std::string input) = 0;

    virtual void print(const char* input) = 0;

    virtual void print(double input) = 0;

    virtual void print(int input) = 0;

protected:
    Controller& controller;
};

#endif //TITRATION_VIEW_H
