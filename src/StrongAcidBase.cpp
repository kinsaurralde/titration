#include "StrongAcidBase.h"
#include <math.h>
#include "view.h"


StrongAcidBase::StrongAcidBase(std::map<std::string, std::string> input_data, int type, View *view) : Reaction(
        std::move(input_data), view), type(type) {
    setup();
}

void StrongAcidBase::setup() {
    num_cycles = stoi(input_data.at("num_cycles"));
    double titrand_conc = 0;
    double titrand_vol = 0;
    try {
        titrant_conc = stod(input_data.at("titrant_conc"));
        titrant_vol = stod(input_data.at("titrant_vol"));
        titrant_mol = titrant_conc * titrant_vol;
        titrand_conc = stod(input_data.at("titrand_conc"));
        titrand_vol = stod(input_data.at("titrand_vol"));
        total_volume = titrand_vol;
    } catch (char *e) {
        std::cout << "Missing parameters" << std::endl;
        std::cout << "Message: " << e << std::endl;
        exit(1);
    }
    std::cout << "Total: " << total_volume << std::endl;

    if (type == 1) {    // SASB
        titrant_is_acid = false;
        base = std::make_unique<Component>(Component());
        acid = std::make_unique<Component>(Component(titrand_conc, titrand_vol));
    } else if (type == 2) { //SBSA
        titrant_is_acid = true;
        acid = std::make_unique<Component>(Component());
        base = std::make_unique<Component>(Component(titrand_conc, titrand_vol));
    } else {
        std::cout << "Invalid type given to StrongAcidBase";
        throw "Invalid type given to StrongAcidBase";
    }

}

void StrongAcidBase::run() {
    double mol_titrant_add_per_cycle = titrant_mol / num_cycles;
    double mol_titrant_added = 0;
    double vol_titrant_add_per_cycle = titrant_vol / num_cycles;
    double vol_titrant_added = 0;
    int i = 0;
    std::cout << "Begining titration" << std::endl;
    std::cout << "Moles titrant added per cycle: " << mol_titrant_add_per_cycle << std::endl;
    std::cout << "Total moles titrant: " << titrant_mol << std::endl;
    //std::cout << "[ " << i << " ] Moles titrant added: " << mol_titrant_added << " Volume titrant added: "
    //          << vol_titrant_added << " Total Volume: " << total_volume << " ";
    //printCurrentData();
    view->printCurrentStep(i, mol_titrant_added, vol_titrant_added);
    while (mol_titrant_added < titrant_mol) {
        i++;
        addTitrant(mol_titrant_add_per_cycle, vol_titrant_add_per_cycle);
        mol_titrant_added += mol_titrant_add_per_cycle;
        vol_titrant_added += vol_titrant_add_per_cycle;
        //std::cout << "[ " << i << " ] Moles titrant added: " << mol_titrant_added << " Volume titrant added: "
        //          << vol_titrant_added << " Total Volume: " << total_volume << " ";
        //printCurrentData();
        view->printCurrentStep(i, mol_titrant_added, vol_titrant_added);
    }
}

void StrongAcidBase::calculatePH() {
    double acid_concentration = acid->getConcentration();
    double base_concentration = base->getConcentration();
    if (acid_concentration < 1e-6 && base_concentration < 1e-6) {
        pH = 7;
    } else if (acid_concentration > base_concentration) {
        pH = -log10(acid_concentration);
    } else {
        pH = 14 - log10(base_concentration);
    }
}

void StrongAcidBase::addTitrant(double moles_added, double volume_added) {
    total_volume += volume_added;
    //std::cout << "Total Volume: " << total_volume << std::endl;
    if (titrant_is_acid) {
        acid->addMoles(base->removeMoles(moles_added, volume_added));
    } else {
        base->addMoles(acid->removeMoles(moles_added, volume_added));
    }
    acid->setTotalVolume(total_volume);
    base->setTotalVolume(total_volume);
}
