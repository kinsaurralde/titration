#include <iostream>
#include <math.h>
#include "component.h"

Component::Component() : concentration(0) , volume(0) , moles(0) , total_volume(0) {}

Component::Component(double concentration, double volume)
        : concentration(concentration) , volume(volume) , total_volume(volume) {
    moles = concentration * volume;
    //std::cout << " Total vaol: " << total_volume << std::endl;
}

double Component::getConcentration() {
    calculateConcentration();
    return concentration;
}

void Component::calculateConcentration() {
    if (total_volume > 0) {
        concentration = moles / total_volume;
        //std::cout << "get: " << moles << " : " << total_volume << " : " << concentration << std::endl;
    } else {
        concentration = 0;
    }
    if (fabs(concentration) < 1e-6) {
        concentration = 0;
    }
}

double Component::getVolume() const {
    return volume;
}

void Component::setTotalVolume(double total) {
    total_volume = total;
}

void Component::changeVolume(double amount) {
    volume += amount;
    total_volume += amount;
    calculateConcentration();
}

double Component::getMoles() const {
    return moles;
}

double Component::add(double volume_added) {    // dont use for now
    /*moles += (concentration * volume_added);
    volume += volume_added;
    return 0;*/
}

double Component::remove(double volume_removed) {    // dont use for now
    /*double change_moles = concentration * volume_removed;
    if (moles - change_moles >= 0) {
        moles -= change_moles;
        return 0;
    } else {
        double remaining_moles = change_moles - moles;
        moles = 0;
        return remaining_moles / concentration;
    }*/
}

double Component::addMoles(double amount) {
    return addMoles(amount, 0);
}

double Component::removeMoles(double amount) {
    return removeMoles(amount, 0).first;
}

double Component::addMoles(std::pair<double, double> amount_volume) {
    return addMoles(amount_volume.first, amount_volume.second);
}

std::pair<double, double> Component::removeMoles(std::pair<double, double> amount_volume) {
    return removeMoles(amount_volume.first, amount_volume.second);
}

double Component::addMoles(double amount, double volume_added) {
    moles += amount;
    changeVolume(volume_added);
    return 0;
}

std::pair<double, double> Component::removeMoles(double amount, double volume_added) {
    if (moles - amount >= 0) {
        moles -= amount;
        changeVolume(volume_added);
        return {0,0};
    } else {
        double moles_removed = moles;
        double volume_removed;
        if (fabs(concentration) < 1e-6) {
            volume_removed = 0;
        } else {
            volume_removed = moles_removed / concentration;
        }
        removeMoles(moles_removed, volume_removed);
        return {amount - moles_removed, volume_added - volume_removed};
    }
}
