#ifndef SAMPLE_PARSE_H
#define SAMPLE_PARSE_H

#include <vector>

std::vector<const char *> sample = {
        R"({"type": "SASB", "num_cycles": "1000", "titrant_conc": ".1","titrant_vol": ".004","titrand_conc": ".1","titrand_vol": ".002"})",
        R"({"type": "SASB", "num_cycles": "1000", "titrant_conc": ".1","titrant_vol": ".01","titrand_conc": ".2","titrand_vol": ".02"})",
        R"({"type": "SASB", "num_cycles": "1000", "titrant_conc": ".1","titrant_vol": ".01","titrand_conc": ".2","titrand_vol": ".02"})"};

#endif //SAMPLE_PARSE_H