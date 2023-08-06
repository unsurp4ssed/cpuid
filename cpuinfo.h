//
// Created by admin on 06.08.2023.
//

#ifndef CPUID_CPUINFO_H
#define CPUID_CPUINFO_H
#include <cpuid.h>
#include <string>

unsigned int getModel();
unsigned int getStepping();
unsigned int getFamily();
std::string getCPUType();
std::string getBrand();

#endif //CPUID_CPUINFO_H
