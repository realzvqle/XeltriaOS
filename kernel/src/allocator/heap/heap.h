#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED




#include "../../kernel.h"


typedef struct _KHEAP {
    uint64_t start;
    uint64_t end;
    uint64_t current;
} KHEAP;


bool KeInitializeHeapMemory(KHEAP* heap, uint32_t size);
void* KeAllocateHeapMemory(KHEAP* heap, uint32_t size);
bool KeResetHeapMemory(KHEAP* heap);

#endif