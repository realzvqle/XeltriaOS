#include "patterns.h"
#include "ramfb.h"
#include "terminal.h"
#include "uart.h"


fb_info fb;

extern void KiJumpToUserMode();


void KiEntry(void) {
    //KiSetupExceptionVectorTable();
    KiJumpToUserMode();
    //KiSerialPrint("");

    // will never be reached
    KiTerminalPrint("Hi!");
    while(1) continue;
}



