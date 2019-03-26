#ifndef TITRATION_CONSOLEVIEW_H
#define TITRATION_CONSOLEVIEW_H

#include <ios>
#include "view.h"

class StandardView : public View {
public:
    StandardView(Controller &controller, std::ostream& stream);

    void printCurrentStep() override;

    void printCurrentStep(int i) override;

    void printCurrentStep(int i, double moles_added, double volume_added) override;

    void print(std::string input) override;

    void print(const char *input) override;

    void print(double input) override;

    void print(int input) override;

protected:
    std::ostream& stream;
};

#endif //TITRATION_CONSOLEVIEW_H
