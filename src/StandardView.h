#ifndef TITRATION_CONSOLEVIEW_H
#define TITRATION_CONSOLEVIEW_H

#include <ios>
#include <fstream>
#include <sstream>
#include "view.h"

class StandardView : public View {
public:
    StandardView(Controller &controller, std::ostream &stream);

    void printCurrentStep() override;

    void printCurrentStep(std::ostream &out);

    void printCurrentStep(int i, double moles_added, double volume_added) override;

    void printCurrentStep(std::ostream& out, int i, double moles_added, double volume_added);

    void printOutAndCSV(std::ostream& out, std::string string);

    void printScreen() override;

    void printFile() override;

    void printCSV();

    void print(std::string input) override;

    void print(const char *input) override;

    void print(double input) override;

    void print(int input) override;

protected:
    std::stringstream record;
    std::stringstream csv_record;
    std::ostream &stream;

    std::string out_file_path;
};

#endif //TITRATION_CONSOLEVIEW_H
