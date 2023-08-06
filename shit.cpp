#include <stdio.h>
#include <string.h>
#include <cpuid.h>
#include <string.h>



int main()
{
    unsigned int regs[12];
    char brand[sizeof(regs)];

    __cpuid(0x80000000, regs[0], regs[1], regs[2], regs[3]);

    if (regs[0] < 0x80000004)
        return 1;

    __cpuid(0x80000002, regs[0], regs[1], regs[2], regs[3]);
    __cpuid(0x80000003, regs[4], regs[5], regs[6], regs[7]);
    __cpuid(0x80000004, regs[8], regs[9], regs[10], regs[11]);

    memcpy(brand, regs, sizeof(regs));
    printf("%s\n", brand);


    unsigned int eax, ebx, ecx, edx;
    unsigned int l2size, assoc, cache;

    __cpuid(0x80000006, eax, ebx, ecx, edx);

    l2size = ecx & 0xff;
    assoc = (ecx >> 12) & 0x07;
    cache = (ecx >> 16) & 0xffff;

    printf("L2 CACHE: Line size: %d B, Assoc. type: %d, Cache size: %d KB.\n", l2size, assoc, cache);

    __cpuid(0x1, eax, ebx, ecx, edx);

    unsigned int stepping, model, family;
    unsigned int cpuType;

    stepping = eax & 0xf;
    model = model1();
    family = (eax >> 8) & 0xf;

    cpuType = (eax >> 12) & 0x2;
    char cpuTypeString[10];
    switch (cpuType) {
        case 0b00: strcpy(cpuTypeString, "Standard"); break;
        case 0b01: strcpy(cpuTypeString, "Overdrive"); break;
        case 0b10: strcpy(cpuTypeString, "Dual"); break;
        case 0b11: strcpy(cpuTypeString, "Error :("); break;
    }
    //extModel = ((eax >> 12) & 0xf) + model;

    printf("EAX is %d\n", eax);
    printf("MODEL: %d\n"
           "STEPPING: %d\n"
           "FAMILY:%x\n",
           model, stepping, family);

    printf("cputype: %s\n", cpuTypeString);

    return 0;
}//
// Created by admin on 06.08.2023.
//
