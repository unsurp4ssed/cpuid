#include <iostream>
#include <bitset>
#include <array>
#include "cpuinfo.h"

int main() {
    std::cout << getBrand() << std::endl;
    std::cout << "Model: " << getModel() << std::endl;
    std::cout << "Stepping: " << getStepping() << std::endl;
    std::cout << "Family: " << std::hex <<  getFamily()  << std::dec << std::endl;
    std::cout << "CPU type: " << getCPUType() << std::endl;

    return 0;
}