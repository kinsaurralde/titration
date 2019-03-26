#ifndef TITRATION_COMPONENT_H
#define TITRATION_COMPONENT_H

#include <utility>

class Component {
public:
    Component();

    Component(double concentration, double volume);

    double getConcentration();

    void calculateConcentration();

    double getVolume() const;

    void setTotalVolume(double total);

    double add(double volume_added);

    double remove(double volume_removed);

    double addMoles(double amount);

    double removeMoles(double amount);

    double addMoles(double amount, double volume_added);

    std::pair<double, double> removeMoles(double amount, double volume_added);

    double addMoles(std::pair<double, double> amount_volume);

    std::pair<double, double> removeMoles(std::pair<double, double> amount_volume);

    double getMoles() const;

    void changeVolume(double amount);


protected:
    double concentration;
    double volume;
    double total_volume;
    double moles;
};

#endif //TITRATION_COMPONENT_H
