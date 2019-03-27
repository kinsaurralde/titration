#ifndef TITRATION_SETTINGS_H
#define TITRATION_SETTINGS_H

#include <iostream>

class Settings {
public:
    Settings();

protected:
public:
    bool isPrint_to_stream() const;

    void setPrint_to_stream(bool print_to_stream);

    std::ostream &getStream() const;

    void setStream(std::ostream &stream);

protected:
    bool print_to_stream;
    std::ostream &stream;
};

#endif //TITRATION_SETTINGS_H
