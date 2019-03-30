#include "AWSView.h"

AWSView::AWSView(Controller &controller, std::ostream &stream) : View(controller),
                                                                 return_json(controller.getSettings().getReturn_json()),
                                                                 allocator(return_json.GetAllocator()) {
    return_json.SetObject();
    rapidjson::Value array(rapidjson::kArrayType);
    //return_json.AddMember("data", allocator);
}

void AWSView::printCurrentStep() {

}

void AWSView::printCurrentStep(int i, double moles_added, double volume_added) {
    //std::vector<std::pair<std::string, std::string>> current_step;
    std::map<std::string, std::string> current_step;
    Reaction *rxn = controller.getReaction().get();
    current_step.emplace(std::make_pair("id", std::to_string(i)));
    current_step.emplace(std::make_pair("moles_titrant", std::to_string(moles_added)));
    current_step.emplace(std::make_pair("volume_titrant", std::to_string(volume_added)));
    current_step.emplace(std::make_pair("moles_acid", std::to_string(rxn->getAcid()->getMoles())));
    current_step.emplace(std::make_pair("concentration_acid", std::to_string(rxn->getAcid()->getConcentration())));
    current_step.emplace(std::make_pair("moles_base", std::to_string(rxn->getBase()->getMoles())));
    current_step.emplace(std::make_pair("concentration_base", std::to_string(rxn->getBase()->getConcentration())));
    current_step.emplace(std::make_pair("total_volume", std::to_string(rxn->getTotal_volume())));
    current_step.emplace(std::make_pair("pH", std::to_string(rxn->getPH())));
    data.emplace_back(current_step);
}

void AWSView::print(std::string input) {

}

void AWSView::print(const char *input) {

}

void AWSView::print(double input) {

}

void AWSView::print(int input) {

}

void AWSView::printFile() {
    return_json.AddMember("calc_time", controller.getSettings().getExecuteTime(), allocator);
    rapidjson::Value values(rapidjson::kArrayType);
    for (auto& itr : data) {
        rapidjson::Value current_value;
        current_value.SetObject();
        addMember(current_value, "id",itr["id"]);
        addMember(current_value, "moles_titrant",itr["moles_titrant"]);
        addMember(current_value, "volume_titrant",itr["volume_titrant"]);
        addMember(current_value, "moles_acid",itr["moles_acid"]);
        addMember(current_value, "concentration_acid",itr["concentration_acid"]);
        addMember(current_value, "moles_base",itr["moles_base"]);
        addMember(current_value, "concentration_base",itr["concentration_base"]);
        addMember(current_value, "total_volume",itr["total_volume"]);
        addMember(current_value, "pH",itr["pH"]);
        values.PushBack(current_value, allocator);
    }
    return_json.AddMember("data", values, allocator);
}

void AWSView::addMember(rapidjson::Value &current_row, std::string key, std::string value) {
    rapidjson::Value str_key(rapidjson::kObjectType);
    str_key.SetString(key.c_str(), key.length(), allocator);
    rapidjson::Value str_value(rapidjson::kObjectType);
    str_value.SetString(value.c_str(), value.length(), allocator);
    current_row.AddMember(str_key, str_value, allocator);
}
