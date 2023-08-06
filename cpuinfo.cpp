//
// Created by admin on 06.08.2023.
//

#include "cpuinfo.h"
#include <cstring>

unsigned int getModel() {
    unsigned int eax, ebx, ecx, edx;
    __cpuid(0x1, eax, ebx, ecx, edx);
    return (eax >> 4) & 0xf;
}

unsigned int getStepping() {
    unsigned int eax, ebx, ecx, edx;
    __cpuid(0x1, eax, ebx, ecx, edx);
    return eax & 0xf;
}

unsigned int getFamily() {
    unsigned int eax, ebx, ecx, edx;
    __cpuid(0x1, eax, ebx, ecx, edx);
    return (eax >> 8) & 0xf;
}

std::string getCPUType() {
    unsigned int eax, ebx, ecx, edx;
    __cpuid(0x1, eax, ebx, ecx, edx);
    unsigned int cpuType = (eax >> 12) & 0x2;
    std::string cpuTypeString;
    switch (cpuType) {
        case 0b00: cpuTypeString = "Standard"; break;
        case 0b01: cpuTypeString = "Overdrive"; break;
        case 0b10: cpuTypeString = "Dual"; break;
        case 0b11: cpuTypeString = "Error :("; break;
    }
    return cpuTypeString;
}

std::string getBrand() {
    unsigned int regs[12];
    char brand[sizeof(regs)];

    __cpuid(0x80000000, regs[0], regs[1], regs[2], regs[3]);

    if (regs[0] < 0x80000004)
        return "unknown";

    __cpuid(0x80000002, regs[0], regs[1], regs[2], regs[3]);
    __cpuid(0x80000003, regs[4], regs[5], regs[6], regs[7]);
    __cpuid(0x80000004, regs[8], regs[9], regs[10], regs[11]);

    memcpy(brand, regs, sizeof(regs));
    std::string brand_;
    brand_ = brand;
    return brand_;
}
