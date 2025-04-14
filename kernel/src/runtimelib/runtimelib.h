#ifndef RUNTIMELIB_H_INCLUDED
#define RUNTIMELIB_H_INCLUDED






#include "../kernel.h"

char* RtlIntegerToAscii(int num, char* str) ;
void RtlPrintUnsigned64IntegerIntoUart(char* prev, uint64_t integer);

#endif