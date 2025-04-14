#include "allocator/heap/heap.h"
#include "devices/uart/uart.h"
#include "time/time.h"



void KiEntry(void) {
    KiPrintStringToUart("\n\n! XeltriaOS !\n\n");
    KiPrintStringToUart("Heap Allocator Test\n\n");
    KHEAP heap;
    bool result = KeInitializeHeapMemory(&heap, 1000);
    if(!result){
        KiPrintStringToUart("Failed to Create Heap Memory\n");
        while(1){continue;}
    }
    char* hi = KeAllocateHeapMemory(&heap, 3);
    hi[0] = 's';
    hi[1] = 'i';
    hi[2] = '\0';
    char* qi = KeAllocateHeapMemory(&heap, 3);
    qi[0] = 'p';
    qi[1] = 'i';
    qi[2] = '\0';
    KiPrintStringToUart(hi);
    KiPrintStringToUart(qi);
    KiPrintStringToUart(hi);
    while(1){
        KiWait(10);
    }
}



