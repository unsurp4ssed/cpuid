//
// Created by admin on 06.08.2023.
//

#ifndef CPUID_CPUINFO_H
#define CPUID_CPUINFO_H
#include <cpuid.h>
#include <string>
#include <iostream>

unsigned int cpu_model();
unsigned int cpu_stepping();
unsigned int cpu_family();
std::string vendor_ID();
std::string cpu_type();
std::string cpu_name();

class L1cache {

};

class L2cache {
};

class L3cache {

};

#endif //CPUID_CPUINFO_H