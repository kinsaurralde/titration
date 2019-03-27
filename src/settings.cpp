#include "settings.h"

Settings::Settings() : print_to_stream(true) , stream(std::cout) {

}

bool Settings::isPrint_to_stream() const {
    return print_to_stream;
}

void Settings::setPrint_to_stream(bool print_to_stream) {
    Settings::print_to_stream = print_to_stream;
}

std::ostream &Settings::getStream() const {
    return stream;
}

