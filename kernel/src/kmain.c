#include "sysintegrity/error.h"
#include "drivers/ramfb/ramfb.h"
fb_info fb;

extern void KiJumpToUserMode();


void KiEntry(void) {
    KiPanic("MANUAL_CRASH");
    while(1) continue;
}



