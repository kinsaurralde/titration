#ifndef TITRATION_COMPONENT_H
#define TITRATION_COMPONENT_H

class Component {
public:
    Component();

    Component(double concentration, double volume);

    double getConcentration() const;

    double getVolume() const;

protected:
    double concentration;
    double volume;
};

#endif //TITRATION_COMPONENT_H
