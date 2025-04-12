#include "mmio.h"
#include <stdint.h>



void KiWriteToMemory64(uint64_t address, uint64_t value){
    volatile uint64_t* addr = (volatile uint64_t *) address;
    *addr = value;
}

uint64_t KiReadMemory64(uint64_t address){
    volatile uint64_t* addr = (volatile uint64_t *) address;
    return *addr;
}

