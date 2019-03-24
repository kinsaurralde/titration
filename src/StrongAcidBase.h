#ifndef TITRATION_STRONGACIDBASE_H
#define TITRATION_STRONGACIDBASE_H

#include "reaction.h"

class StrongAcidBase : public Reaction {
public:
    StrongAcidBase(std::map<std::string, std::string> input_data, int type);

    void setup() override;

    void run() override;

    void calculatePH() override;

protected:
    int type; // 0 is SASB , 1 is SBSA
};

#endif //TITRATION_STRONGACIDBASE_H
