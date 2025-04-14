#include "heap.h"
#include "../../devices/memory.h"



// simple linear bump allocator

#define BEGIN_HEAP_MEMORY 0x43000000
#define END_HEAP_MEMORY 0x46000000
static uint64_t s_Current = 0;



bool KeInitializeHeapMemory(KHEAP* heap, uint32_t size){
    if(s_Current == 0) s_Current = BEGIN_HEAP_MEMORY;
    if(s_Current >= END_HEAP_MEMORY || s_Current + size >= END_HEAP_MEMORY) return false;

    heap->start = s_Current;
    heap->end = heap->start + size;
    heap->current = heap->start;

    s_Current += size;

    return true;
}

void* KeAllocateHeapMemory(KHEAP* heap, uint32_t size){
    if(heap->current + size > heap->end){
        return NULL;
    }
    int cur = heap->current;
    heap->current = heap->current + size;
    return (void*)KiReturnMemory64(cur);
}


bool KeResetHeapMemory(KHEAP* heap){
    heap->current = heap->start;
    return true;
}

