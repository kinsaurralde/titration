#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <map>
#include <memory>
#include "reaction.h"

enum titration_type {
    NONE = 0,
    SASB = 1,
    SBSA = 2,
    SAWB = 3,
    SBWA = 4,
};

class Controller {
   public:
    explicit Controller(std::map<std::string,std::string> input);

    void setupReaction();

    void run();

    bool error;
    std::string error_message;

   protected:
    std::map<std::string, std::string> input_data;
    bool is_setup;
    titration_type type;
    std::unique_ptr<Reaction> reaction;
};

#endif  // CONTROLLER_H