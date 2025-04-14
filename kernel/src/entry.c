#include "allocator/heap/heap.h"
#include "bugcheck/bugcheck.h"
#include "devices/memory.h"
#include "devices/uart/uart.h"
#include "time/time.h"
#include "exceptions/exceptions.h"


void KiEntry(void) {
    KiSetupExceptions();
    KiPrintStringToUart("\n\n! XeltriaOS !\n\n");

    // causes an exception
    KiWriteToMemory64(0x50000000, 10);
    while(1){
        KiWait(10);
    }
}



