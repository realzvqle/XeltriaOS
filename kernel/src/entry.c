#include "devices/mmio.h"
#include "devices/uart/uart.h"

void KiEntry(void) {
    KiPrintStringToUart("\n\nzvqle is cool\n\n");
    while(1){
        KiWriteToUart(KiReadUart());
    }
}



