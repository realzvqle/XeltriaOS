#include "mmio.h"



uint8_t KiRead8(volatile uint8_t* addr) {
    return *((volatile uint8_t *) addr);
}

void KiWrite8(volatile uint8_t* addr, uint8_t value) {
    *addr = value;
}


uint32_t KiRead16(volatile uint16_t* addr) {
    return *((volatile uint32_t *) addr);
}

void KiWrite16(volatile uint16_t* addr, uint16_t value) {
    *((volatile uint16_t *) addr) = value;
}


uint32_t KiRead32(volatile uint32_t* addr) {
    return *((volatile uint32_t *) addr);
}

void KiWrite32(volatile uint32_t* addr, uint32_t value) {
    *((volatile uint32_t *) addr) = value;
}



uint64_t KiRead64(volatile uint64_t* addr) {
    return *((volatile uint64_t *) addr);
}

void KiWrite64(volatile uint64_t* addr, uint64_t value) {
    *((volatile uint64_t *) addr) = value;
}