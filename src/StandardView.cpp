#include "StandardView.h"

#include <iomanip>

StandardView::StandardView(Controller &controller, std::ostream &stream) : View(controller), stream(stream) {
    out_file_path = "output/lastest";
    csv_record << "Moles Titrant Added,Volume Titrant Added,Moles Acid,[A],Moles Base,[B],Total Volume,pH" << std::endl;
}

void StandardView::printCurrentStep(std::ostream &out) {

}

void StandardView::printCurrentStep() {
    printCurrentStep(record);
}

void StandardView::printCurrentStep(std::ostream &out, int i, double moles_added, double volume_added) {
    Reaction *rxn = controller.getReaction().get();
    out << "[ " << std::setw(4) << std::setfill('0') << i << " ] ";
    out << std::fixed << std::setprecision(8);
    out << "M Titrant Add: ";
    printOutAndCSV(out, std::to_string(moles_added));
    out << "  |  ";
    out << "V Titrant Add: ";
    printOutAndCSV(out, std::to_string(volume_added));
    out << "  |  ";
    out << "A Moles: ";
    printOutAndCSV(out, std::to_string(rxn->getAcid()->getMoles()));
    out << "  |  ";
    out << "[A]: ";
    printOutAndCSV(out, std::to_string(rxn->getAcid()->getConcentration()));
    out << "  |  ";
    out << "B Moles: ";
    printOutAndCSV(out, std::to_string(rxn->getBase()->getMoles()));
    out << "  |  ";
    out << "[B]: ";
    printOutAndCSV(out, std::to_string(rxn->getBase()->getConcentration()));
    out << "  |  ";
    out << "T Volume: ";
    printOutAndCSV(out, std::to_string(rxn->getTotal_volume()));
    out << "  |  ";
    out << std::setprecision(4);
    out << "pH: ";
    printOutAndCSV(out, std::to_string(rxn->getPH()));
    out << std::endl;
    csv_record << std::endl;
}

void StandardView::printCurrentStep(int i, double moles_added, double volume_added) {
    printCurrentStep(record, i, moles_added, volume_added);
}

void StandardView::printScreen() {
    std::cout << "Printing to stream" << std::endl;
    std::string line;
    while (std::getline(record, line, '\n')) {  // allows ^C to be used if printing takes too long
        stream << line << std::endl;
    }
}

void StandardView::printFile() {
    std::cout << "Printing to file: " << out_file_path << ".txt" << std::endl;
    std::ofstream file(out_file_path+".txt");
    file << record.str();
    file.close();
}

void StandardView::printCSV() {
    std::cout << "Printing CSV to file: " << out_file_path << "_csv.txt" << std::endl;
    std::ofstream file(out_file_path+"_csv.txt");
    file << csv_record.str();
    file.close();
}

void StandardView::printOutAndCSV(std::ostream &out, std::string string) {
    out << string;
    csv_record << string << ",";
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

