#include "uart.h"
#include "../memory.h"
#include <stdint.h>




void KiWriteToUart(char c){
    KiWriteToMemory64(0x09000000, c);
}


char KiReadUart(){
    return KiReadMemory64(0x09000000);
}


char KiReadUartAndWait(){
    // not implemented
    return '?';
}




void KiPrintStringToUart(const char* string){
    while(*string != '\0'){
        KiWriteToUart(*string);
        string++;
    }
}


