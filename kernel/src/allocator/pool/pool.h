#ifndef POOL_H_INCLUDED
#define POOL_H_INCLUDED






#include "../../kernel.h"


typedef struct _KPOOL {
    uint64_t start;
    uint64_t end;
    uint64_t singAlloc;
    uint64_t current;
} KPOOL;


bool KeInitializePoolMemory(KPOOL* pool, uint32_t size, uint32_t singleAllocationSize);
void* KeAllocatePoolMemory(KPOOL* pool);
bool KeResetPoolMemory(KPOOL* pool);

#endif