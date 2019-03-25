#include "component.h"

Component::Component() : concentration(0) , volume(0) {}

Component::Component(double concentration, double volume) : concentration(concentration) , volume(volume) {}

double Component::getConcentration() const {
    return concentration;
}

double Component::getVolume() const {
    return volume;
}
