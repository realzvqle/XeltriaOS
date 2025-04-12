#include "uart.h"
#include "../mmio.h"




void KiWriteToUart(char c){
    KiWriteToMemory64(0x09000000, c);
}


char KiReadUart(){
    return KiReadMemory64(0x09000000);
}

char KiReadUartAndWait(){
    // read and wait, didn't implement this yet =(
    return '?';
}

void KiPrintStringToUart(const char* string){
    while(*string != '\0'){
        KiWriteToUart(*string);
        string++;
    }
}


