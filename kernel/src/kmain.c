#include "uart.h"
#include "malloc.h"




void KiEntry(void) {
    char* idk = KiSerialGets(1024);
    KiSerialPrint(idk);
    KiFreeMemory(idk);
}