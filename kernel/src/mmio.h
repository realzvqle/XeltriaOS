#ifndef MMIO_H_INCLUDED
#define MMIO_H_INCLUDED






#include "superheader.h"

uint8_t KiRead8(volatile uint8_t* addr);
void KiWrite8(volatile uint8_t* addr, uint8_t value);
uint32_t KiRead16(volatile uint16_t* addr);
void KiWrite16(volatile uint16_t* addr, uint16_t value);
uint32_t KiRead32(volatile uint32_t* addr);
void KiWrite32(volatile uint32_t* addr, uint32_t value);
uint64_t KiRead64(volatile uint64_t* addr);
void KiWrite64(volatile uint64_t* addr, uint64_t value);
uint16_t KiBSwap16(uint16_t x);
uint32_t KiBSwap32(uint32_t x);
uint64_t KiBSwap64(uint64_t x);
void KiWriteBSwap16(uint64_t addr, uint16_t val);
uint16_t KiReadBSwap16(uint64_t addr);
uint16_t KiReadBSwap32(uint64_t addr);
uint64_t KiReadBSWap64(uint64_t addr);
void KiWriteBSwap64(uint64_t addr, uint64_t val);
int KiCompareMemoryString(void *str1, void *str2, uint64_t count);
void KiCopyMemory(void *dest, void *src, uint64_t n);
#endif