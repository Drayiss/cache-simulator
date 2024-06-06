#include "CacheSim.h"
#include <sstream>

std::tuple<bool, std::uint64_t, int> parse_line(const std::string& access);

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
        auto [type, address, instructions] = parse_line(line);
    }
}

// Helper methods
std::tuple<bool, std::uint64_t, int> parse_line(const std::string& access) {
    int type; // 0 is Load, 1 is Store
    std::uint64_t address;
    int instructions;

    sscanf(access.c_str(), "# %d %llx %d", &type, &address, &instructions);

    return {type, address, instructions};
}

