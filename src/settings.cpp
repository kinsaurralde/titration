#include "settings.h"

Settings::Settings() : print_to_stream(true) , stream(std::cout) , aws_version(false) , print_to_csv(true) {

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

void Settings::setAws_version(bool aws_version) {
    Settings::aws_version = aws_version;
    if (aws_version) {
        print_to_stream = false;
        print_to_csv = false;
    }
}

bool Settings::isAws_version() const {
    return aws_version;
}

bool Settings::isPrint_to_csv() const {
    return print_to_csv;
}

void Settings::setPrint_to_csv(bool print_to_csv) {
    Settings::print_to_csv = print_to_csv;
}

void Settings::setReturn_json(const rapidjson::Document &return_json) {

}

rapidjson::Document &Settings::getReturn_json() {
    return return_json;
}

