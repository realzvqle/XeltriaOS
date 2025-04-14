#include "runtimelib.h"
#include "../devices/uart/uart.h"


// scuffed impl
char* RtlIntegerToAscii(int num, char* str) {
    int i = 0;
    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }
    do {
        str[i++] = num % 10 + '0';
        num /= 10;
    } while (num > 0);
    if (isNegative) {
        //str[i++] = '-';
    }

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    str[i] = '\0';

    return str;
}


void RtlPrintUnsigned64IntegerIntoUart(char* prev, uint64_t integer){
    KiPrintStringToUart(prev);
    char buffer[512];
    RtlIntegerToAscii(integer, buffer);
    KiPrintStringToUart(buffer);
    KiPrintStringToUart("\n");
}