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

uint16_t KiBSwap16(uint16_t x) {
    return (x << 8) | (x >> 8);
}

uint32_t KiBSwap32(uint32_t x) {
    return ((x & 0xFF000000) >> 24) |
           ((x & 0x00FF0000) >> 8)  |
           ((x & 0x0000FF00) << 8)  |
           ((x & 0x000000FF) << 24);
}

uint64_t KiBSwap64(uint64_t x) {
    return ((x & 0xFF00000000000000ULL) >> 56) |
           ((x & 0x00FF000000000000ULL) >> 40) |
           ((x & 0x0000FF0000000000ULL) >> 24) |
           ((x & 0x000000FF00000000ULL) >> 8)  |
           ((x & 0x00000000FF000000ULL) << 8)  |
           ((x & 0x0000000000FF0000ULL) << 24) |
           ((x & 0x000000000000FF00ULL) << 40) |
           ((x & 0x00000000000000FFULL) << 56);
}

void KiWriteBSwap16(uint64_t addr, uint16_t val) {
    volatile uint16_t *mmio_w = (volatile uint16_t*)addr;
    *mmio_w = KiBSwap16(val);
}

uint16_t KiReadBSwap16(uint64_t addr) {
    return KiBSwap16(*((volatile uint16_t*)addr));
}


uint16_t KiReadBSwap32(uint64_t addr) {
    return KiBSwap32(*((volatile uint32_t*)addr));
}

void KiWriteBSwap64(uint64_t addr, uint64_t val) {
    volatile uint64_t *mmio_w = (volatile uint64_t*)addr;
    *mmio_w = KiBSwap64(val);
}


uint64_t KiReadBSWap64(uint64_t addr) {
    return KiBSwap64(*((volatile uint64_t*)addr));
}

int KiCompareMemoryString(void *str1, void *str2, uint64_t count) {
    unsigned char *s1 = (unsigned char*)str1;
    unsigned char *s2 = (unsigned char*)str2;

    while (count-- > 0) {
        if (*s1++ != *s2++)
        return s1[-1] < s2[-1] ? -1 : 1;
    }
    return 0;
}


void KiCopyMemory(void *dest, void *src, uint64_t n){
   char *csrc = (char *)src;
   char *cdest = (char *)dest;
  
   for (int i=0; i<n; i++)
       cdest[i] = csrc[i];
}