#include "uart.h"
#include "malloc.h"

extern void test();


void KiEntry(void) {
    test();
    KiSerialPrint("Hi!!");
    char* idk = KiSerialGets(1024);
    KiSerialPrint(idk);
    KiFreeMemory(idk);
}