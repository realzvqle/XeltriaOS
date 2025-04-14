#include "allocator/pool/pool.h"
#include "devices/uart/uart.h"
#include "time/time.h"



void KiEntry(void) {
    KiPrintStringToUart("\n\n! XeltriaOS !\n\n");
    KiPrintStringToUart("Heap Allocator Test\n\n");
    KPOOL firstpool;
    KPOOL secondpool;
    KPOOL thirdpool;
    bool result = KeInitializePoolMemory(&firstpool, 30, 20);
    if(!result){
        KiPrintStringToUart("Failure to Create First Pool Memory\n");
    }
    result = KeInitializePoolMemory(&secondpool, 30, 20);
    if(!result){
        KiPrintStringToUart("Failure to Create Second Pool Memory\n");
    }
    char* hi = KeAllocatePoolMemory(&firstpool);
    hi[0] = 's';
    hi[1] = 'i';
    hi[3] = '\n';
    hi[4] = '\0';
    char* qi = KeAllocatePoolMemory(&secondpool);
    qi[0] = 'q';
    qi[1] = 'i';
    qi[3] = '\n';
    qi[4] = '\0';
    KiPrintStringToUart(hi);
    KiPrintStringToUart(qi);
    while(1){
        KiWait(10);
    }
}



