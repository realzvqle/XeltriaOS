#include "devices/mmio.h"
#include "devices/uart/uart.h"
#include "time/time.h"

void KiEntry(void) {
    KiPrintStringToUart("\n\nXeltriaOS Kernel\n\n");
    while(1){
        KiPrintStringToUart("This will print again after 2 seconds\n");
        KiWait(2);
    }
}



