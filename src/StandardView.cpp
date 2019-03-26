#include "StandardView.h"

#include <iomanip>

StandardView::StandardView(Controller &controller, std::ostream& stream) : View(controller), stream(stream) {}

void StandardView::printCurrentStep() {
    Reaction* rxn = controller.getReaction().get();
    stream << "A Moles: " << rxn->getAcid()->getMoles();
    stream << "  |  ";
    stream << "[A]: " << rxn->getAcid()->getConcentration();
    stream << "  |  ";
    stream << "B Moles: " << rxn->getBase()->getMoles();
    stream << "  |  ";
    stream << "[B]: " << rxn->getBase()->getConcentration();
    stream << "  |  ";
    stream << "T Volume: " << rxn->getTotal_volume();
    stream << "  |  ";
    stream << std::setprecision(4);
    stream << "pH: " << rxn->getPH();
    stream << std::endl;
}

void StandardView::printCurrentStep(int i) {
    stream << "[ "  << std::setw(4) << std::setfill('0') << i << " ] ";
    printCurrentStep();
}

void StandardView::printCurrentStep(int i, double moles_added, double volume_added) {
    stream << "[ "  << std::setw(4) << std::setfill('0') << i << " ] ";
    stream << std::fixed << std::setprecision(8);
    stream << "M Titrant Add: " << moles_added;
    stream << "  |  ";
    stream << "V Titrant Add: " << volume_added;
    stream << "  |  ";
    printCurrentStep();
}

void StandardView::print(std::string input) {
    stream << input << std::endl;
}

void StandardView::print(const char *input) {
    stream << input << std::endl;
}

void StandardView::print(double input) {
    stream << input << std::endl;
}

void StandardView::print(int input) {
    stream << input << std::endl;
}

