#include "malloc.h"

static uint8_t memory_pool[MEMORY_SIZE];



static Block* free_list = NULL;

void KiInitializeHeap(void) {
    free_list = (Block*)memory_pool;
    free_list->size = MEMORY_SIZE;
    free_list->next = NULL;
}

static size_t AlignSize(size_t size) {
    size_t alignment = sizeof(Block);
    return (size + alignment - 1) & ~(alignment - 1);
}

void* KiAllocateMemory(size_t size) {
    size = AlignSize(size + sizeof(Block));

    Block* prev = NULL;
    Block* curr = free_list;

    while (curr) {
        if (curr->size >= size) {
            if (curr->size > size + sizeof(Block)) {
                Block* next = (Block*)((uint8_t*)curr + size);
                next->size = curr->size - size;
                next->next = curr->next;
                curr->size = size;
                curr->next = next;
            } 
            else {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    free_list = curr->next;
                }
            }
            return (uint8_t*)curr + sizeof(Block);
        }
        prev = curr;
        curr = curr->next;
    }

    return NULL; 
}

void KiFreeMemory(void* ptr) {
    if (!ptr) return;

    Block* block = (Block*)((uint8_t*)ptr - sizeof(Block));

    block->next = free_list;
    free_list = block;
}



