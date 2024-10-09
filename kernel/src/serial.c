#include "serial.h"






static volatile uint8_t *uart = (uint8_t *) 0x09000000;

void KiSerialPutChar(char c) {
    *uart = c;
}

void KiSerialPrint(const char *s) {
    while(*s != '\0') {
        KiSerialPutChar(*s);
        s++;
    }
}