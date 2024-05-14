#include <iostream>
#include <fstream>
#pragma once

class CacheSim {
public:
    CacheSim(const std::string& input);
    ~CacheSim();
    void run();
private:
    // Input trace file
    std::ifstream infile;
};

