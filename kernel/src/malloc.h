#ifndef MALLOC_H_INCLUDED
#define MALLOC_H_INCLUDED



#include "superheader.h"

#define MEMORY_SIZE 10960  


typedef struct Block {
    size_t size;       
    struct Block* next; 
} Block;

void KiInitializeHeap(void);
void* KiAllocateMemory(size_t size);
void KiFreeMemory(void* ptr);

#endif