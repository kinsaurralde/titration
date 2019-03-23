#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <map>

enum titration_type {
    NONE = 0,
    SASB = 1,
    SBSA = 2,
    SAWB = 3,
    SBWA = 4,
};

class Controller {
   public:
   Controller();
    Controller(std::map<std::string,std::string> input);

    void setup();

    void run();

    bool error;
    std::string error_message;

   protected:
    bool isInputValid();
    titration_type type;
};

#endif  // CONTROLLER_H