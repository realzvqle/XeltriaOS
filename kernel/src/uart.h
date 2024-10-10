#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED




#include "superheader.h"


void KiSerialPutChar(char c) ;
void KiSerialPrint(const char *s);
char KiSerialGetChar();
char* KiSerialGets(int size);

#endif