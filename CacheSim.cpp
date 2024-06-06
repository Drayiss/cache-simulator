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

    std::ofstream cloneFile;
    cloneFile.open("traces/clone.gz");

    while (std::getline(infile, line)) {
        auto [type, address, instructions] = parse_line(line);

        std::ostringstream oss;
        oss << "# " << type << " " << std::hex << address << " " << std::dec << instructions << "\n";
        cloneFile << oss.str();
    }
    cloneFile.close();
}

// Helper methods
std::tuple<bool, std::uint64_t, int> parse_line(const std::string& access) {
    int type; // 0 is Load, 1 is Store
    std::uint64_t address;
    int instructions;

    sscanf(access.c_str(), "# %d %llx %d", &type, &address, &instructions);

    return {type, address, instructions};
}

