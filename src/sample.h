#ifndef SAMPLE_PARSE_H
#define SAMPLE_PARSE_H

#include <vector>

namespace samples {
    const char* test_1 = "{\"type\": \"SASB\",\"titrant_conc\": \".1\",\"titrant_vol\": \".01\",\"titrand_conc\": \".2\",\"titrand_vol\": \".02\"}";
    const char* test_2 = "{\"type\": \"WASB\",\"titrant_conc\": \".2\",\"titrant_vol\": \".21\",\"titrand_conc\": \".22\",\"titrand_vol\": \".22\"}";
    const char* test_3 = "{\"type\": \"WBSA\",\"titrant_conc\": \".3\",\"titrant_vol\": \".31\",\"titrand_conc\": \".23\",\"titrand_vol\": \".32\"}";

};

std::vector<const char*> sample;
//sample.push_back("{\"titrant_conc\": \".1\",\"titrant_vol\": \".01\",\"titrand_conc\": \".2\",\"titrand_vol\": \".02\"}");
//sample.push_back("{\"titrant_conc\": \".\",\"titrant_vol\": \".03\",\"titrand_conc\": \".4\",\"titrand_vol\": \".04\"}");
//sample.push_back("{\"titrant_conc\": \".5\",\"titrant_vol\": \".05\",\"titrand_conc\": \".6\",\"titrand_vol\": \".06\"}");

#endif //SAMPLE_PARSE_H