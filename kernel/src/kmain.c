#include "timer.h"
#include "uart.h"
#include "rng.h"
#include "kistdlib.h"
#include "malloc.h"




void KiEntry(void) {
    KiInitializeHeap();
    char* idk = KiSerialGets(1024);
    KiSerialPrint(idk);
    KiFreeMemory(idk);
}