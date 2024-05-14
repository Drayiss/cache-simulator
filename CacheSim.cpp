#include "CacheSim.h"

CacheSim::CacheSim(const std::string& input) {
    // Initalize input file stream object
    infile.open(input);
}

CacheSim::~CacheSim() {
    infile.close();
}

void CacheSim::run() {
    std::string line;
    while (std::getline(infile, line)) {
        // parse line
    }
}
