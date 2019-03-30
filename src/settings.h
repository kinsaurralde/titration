#ifndef TITRATION_SETTINGS_H
#define TITRATION_SETTINGS_H

#include <iostream>
#include <chrono>
#include "../include/rapidjson/document.h"

class Settings {
public:
    Settings();

protected:
public:
    bool isPrint_to_stream() const;

    void setPrint_to_stream(bool print_to_stream);

    std::ostream &getStream() const;

    void setStream(std::ostream &stream);

    bool isAws_version() const;

    void setAws_version(bool aws_version);

    bool isPrint_to_csv() const;

    void setPrint_to_csv(bool print_to_csv);

    rapidjson::Document &getReturn_json();

    void setReturn_json(const rapidjson::Document &return_json);

    double getExecuteTime();

protected:
    rapidjson::Document return_json;
    bool aws_version;
    bool print_to_stream;
    bool print_to_csv;
    std::ostream &stream;
    std::chrono::_V2::system_clock::time_point time_start;
};

#endif //TITRATION_SETTINGS_H
