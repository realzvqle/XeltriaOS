#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED





#include "../../kernel.h"



void KiWriteToUart(char c);
char KiReadUartAndWait();
char KiReadUart();
void KiPrintStringToUart(const char* string);

#endif