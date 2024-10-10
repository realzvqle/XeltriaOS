#include "timer.h"
#include "uart.h"
#include "rng.h"
#include "kistdlib.h"





void KiEntry(void) {
    while(1){
        char buffer[512];
        KiItoA(KiGenerateRandomValueWithinRange(KiGetTimerValue(), 0, 1000), buffer);
        KiSerialPrint(buffer);
        KiSerialPrint("\n");
        KiSleep(1);
    }
}