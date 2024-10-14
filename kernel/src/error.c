#include "error.h"
#include "drawing.h"
#include "ramfb.h"
#include "uart.h"


extern void KiHaltSystem();

void KiPanic(char* error){
    uint8_t crashttext[3];
    KiCreateRGB(crashttext, 255, 255, 255);
    uint8_t crashcolor[3];
    KiCreateRGB(crashcolor, 0, 0, 0);
    KiDrawRect(0, 10, HEIGHT - 10, WIDTH, crashcolor);
    KiSerialPrint(error);
    KiDrawText(20, 20, ":( OS CRASHED", 1, crashttext);
    KiDrawText(20, 60, error, 1, crashttext);

    KiHaltSystem();
}

// void KiDataAbortHandler(void) {
//     uint64_t fault_address;
//     asm volatile ("mrs %0, FAR_EL1" : "=r"(fault_address)); // Get Fault Address Register

//     KiPanic("Data abort exception occurred.");
// }