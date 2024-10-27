#include "uart.h"
#include "../../malloc.h"
#include "../mmio.h"






static volatile uint8_t *uart = (uint8_t *) 0x09000000;

void KiSerialPutChar(char c) {
    KiWrite8(uart, c);
}



void KiSerialPrint(const char *s) {
    while(*s != '\0') {
        KiSerialPutChar(*s);
        s++;
    }
}

char KiSerialGetChar() {
    return KiRead8(uart);
}

static inline char* ArrayAdder(size_t size) {
    char* array = (char*)KiAllocateMemory(size);
    //if (!array) return NULL;  
    

    for (int jj = 0; jj < size - 1; jj++) {
        array[jj] = '\0';  
    }
    static char former_char;

    int index = 0;
    while (index < (size - 1)) { 

        char character = KiSerialGetChar();
        if(character == former_char) continue;
        if(character == NULL) continue;
        if (character == 'P') {
            array[index] = '\0';  
            break;
        }
        array[index] = character; 
        char temp[2];
        temp[0] = character;
        temp[1] = '\0';  
        index++;
        KiSerialPrint(temp);
        former_char = character;
        
    }
    if (index == (size - 1)) array[size - 1] = '\0';  
    return array;
}


char* KiSerialGets(int size){
    KiSerialPrint("\n> ");
    char* result = ArrayAdder(size);
    KiSerialPrint("\n");
    return result;
}
