#ifndef BUGCHECK_H_INCLUDED
#define BUGCHECK_H_INCLUDED







#include "../kernel.h"


typedef struct _KINTERRUPTFRAME {
    uint64_t x0;
    uint64_t x1;
    uint64_t x2;
    uint64_t x3;
    uint64_t x4;
    uint64_t x5;
    uint64_t x6;
    uint64_t x7;
    uint64_t x8;
    uint64_t x9;
    uint64_t x10;
    uint64_t x11;
    uint64_t x12;
    uint64_t x13;
    uint64_t x14;
    uint64_t x15;
    uint64_t x16;
    uint64_t x17;
    uint64_t x18;
    uint64_t fp;
    uint64_t lr;
    uint64_t xzr;
    uint64_t esr;
    uint64_t far;
} KINTERRUPTFRAME;

void KeBugCheck(char* error);
void KiDumpRegistersToUart();
void KiDumpRegistersToUart();

#endif