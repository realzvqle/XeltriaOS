#include "pool.h"
#include "../../devices/memory.h"
#include <stdint.h>

#define BEGIN_POOL_MEMORY 0x41000000
#define END_POOL_MEMORY 0x43000000
static uint64_t s_Current = 0;


bool KeInitializePoolMemory(KPOOL* pool, uint32_t size, uint32_t singleAllocationSize){
    if(s_Current == 0) s_Current = BEGIN_POOL_MEMORY;
    if(s_Current >= END_POOL_MEMORY || s_Current + size >= END_POOL_MEMORY) return false;

    pool->start = s_Current;
    pool->end = pool->start + size;
    pool->singAlloc = singleAllocationSize;
    pool->current = pool->start;

    s_Current += size;

    return true;
}

void* KeAllocatePoolMemory(KPOOL* pool){
    if(pool->current > pool->end){
        return NULL;
    }
    int cur = pool->current;
    pool->current = pool->current + pool->singAlloc;
    return (void*)KiReturnMemory64(cur);
}

bool KeResetPoolMemory(KPOOL* pool){
    pool->current = pool->start;
    return true;
}

