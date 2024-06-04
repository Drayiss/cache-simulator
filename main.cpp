#include "CacheSim.h"

int main() {
    auto simulator = CacheSim("traces/art.trace.gz");
    simulator.run();
    return 0;
}