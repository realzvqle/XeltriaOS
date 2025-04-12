#include "mmio.h"
#include <stdint.h>


//uint8_t KiRead8(volatile uint8_t* addr) {
//     return *((volatile uint8_t *) addr);
// }

// void KiWrite8(volatile uint8_t* addr, uint8_t value) {
//     *addr = value;
// }


void KiWriteToMemory64(uint64_t address, uint64_t value){
    volatile uint64_t* addr = (volatile uint64_t *) address;
    *addr = value;
}

uint64_t KiReadMemory64(uint64_t address){
    volatile uint64_t* addr = (volatile uint64_t *) address;
    return *addr;
}