#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED





#include "../kernel.h"




void KiWriteToMemory64(uint64_t address, uint64_t value);
uint64_t KiReadMemory64(uint64_t address);
volatile void* KiReturnMemory64(uint64_t address);

#endif