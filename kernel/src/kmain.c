#include "error.h"
#include "loading.h"
#include "uart.h"
#include "ramfb.h"
#include "terminal.h"
#include "timer.h"
#include "rng.h"
#include "kistdlib.h"
fb_info fb;

void KiCheckSystemIntegrity();


void KiEntry(void) {
    KiDrawLoadingScreen();
    while(1) continue;
}



