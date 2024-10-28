#include "kdebugshell/kserterm.h"
#include "drivers/ramfb/ramfb.h"
#include "terminal/terminal.h"


fb_info fb;

extern void KiJumpToUserMode();


void KiEntry(void) {
    KiBeginKernelDebuggingShell();
    KiTerminalPrint("Hi!");
    while(1) continue;
}



