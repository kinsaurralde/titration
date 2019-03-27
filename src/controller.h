#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <map>
#include <memory>
#include "reaction.h"
#include "view.h"
#include "settings.h"

enum titration_type {
    NONE = 0,
    SASB = 1,
    SBSA = 2,
    SAWB = 3,
    SBWA = 4,
};

class View;

class Reaction;

class Controller {
   public:
    explicit Controller(std::map<std::string, std::string> input, Settings &settings);

    void applySettings();

    void setupReaction();

    void run();

    const std::unique_ptr<Reaction> &getReaction() const;

    bool error;
    std::string error_message;

   protected:
    Settings& settings;
public:
    Settings &getSettings() const;

protected:
    std::map<std::string, std::string> input_data;
    bool is_setup;
    titration_type type;
    std::unique_ptr<Reaction> reaction;
    std::unique_ptr<View> view;
};

#endif  // CONTROLLER_H