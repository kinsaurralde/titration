#ifndef TITRATION_AWSVIEW_H
#define TITRATION_AWSVIEW_H

#include <vector>
#include "view.h"
#include "../include/rapidjson/document.h"

class AWSView : public View {
public:
    AWSView(Controller &controller, std::ostream &stream);

    void printCurrentStep() override;

    void printCurrentStep(int i, double moles_added, double volume_added) override;

    void print(std::string input) override;

    void print(const char *input) override;

    void print(double input) override;

    void printFile() override;

    void print(int input) override;

    void addMember(rapidjson::Value &current_row, std::string key, std::string value);

protected:
    std::vector<std::map<std::string, std::string>> data;
    rapidjson::Document& return_json;
    rapidjson::Document::AllocatorType &allocator;
};

#endif //TITRATION_AWSVIEW_H
