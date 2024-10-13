#include "error.h"
#include "ramfb.h"
#include "terminal.h"
#include "timer.h"
#include "rng.h"
#include "kistdlib.h"
fb_info fb;

void KiCheckSystemIntegrity();


void KiEntry(void) {
    KiPanic("System Error Acc");
    while(1){
        int i = KiGenerateRandomValueWithinRange(KiGetTimerValue(), 0, 10000);
        char buffer[512];
        KiItoA(i, buffer);
        KiTerminalPrint(buffer);
        KiSleep(1);
    }
    
    while(1) continue;
}



