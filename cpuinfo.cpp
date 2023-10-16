//
// Created by admin on 06.08.2023.
//

#include "cpuinfo.h"
#include <cstring>

unsigned int cpu_model() {
    unsigned int eax, ebx, ecx, edx;
    __cpuid(0x1, eax, ebx, ecx, edx);
    return (eax >> 4) & 0xf;
}

unsigned int cpu_stepping() {
    unsigned int eax, ebx, ecx, edx;
    __cpuid(0x1, eax, ebx, ecx, edx);
    return eax & 0xf;
}

unsigned int cpu_family() {
    unsigned int eax, ebx, ecx, edx;
    __cpuid(0x1, eax, ebx, ecx, edx);
    return (eax >> 8) & 0xf;
}

//for extended feature bits and processor info use eax=0x80000001

std::string vendor_ID() {
    int regs[4];
    char vendor[sizeof(regs)];
    __cpuid(0x0, regs[0], regs[1], regs[2], regs[3]);

    memset(vendor, 0, sizeof(vendor));
    *reinterpret_cast<int*>(vendor) = regs[1];
    *reinterpret_cast<int*>(vendor + 4) = regs[3];
    *reinterpret_cast<int*>(vendor + 8) = regs[2];

    std::string vendor_;
    vendor_ = vendor;
    return vendor_;
}

std::string cpu_type() {
    unsigned int eax, ebx, ecx, edx;
    __cpuid(0x1, eax, ebx, ecx, edx);
    unsigned int cpuType = (eax >> 12) & 0x2;
    std::string result;
    switch (cpuType) {
        case 0b00: result = "Standard";  break;
        case 0b01: result = "Overdrive"; break;
        case 0b10: result = "Dual";      break;
        case 0b11: result = "unknown";   break;
        default:   result = "Error";     break;
    }
    return result;
}

std::string cpu_name() {
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
