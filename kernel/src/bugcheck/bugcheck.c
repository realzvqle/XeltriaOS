#include "bugcheck.h"
#include "../runtimelib/runtimelib.h"
#include "../devices/uart/uart.h"

extern void KiStartBugcheckRegisterDump();


void KiDumpRegisterInformation(KINTERRUPTFRAME* frame){
    RtlPrintUnsigned64IntegerIntoUart("X0: ", frame->x0);
    RtlPrintUnsigned64IntegerIntoUart("X1: ", frame->x1);
    RtlPrintUnsigned64IntegerIntoUart("X2: ", frame->x2);
    RtlPrintUnsigned64IntegerIntoUart("X3: ", frame->x3);
    RtlPrintUnsigned64IntegerIntoUart("X4: ", frame->x4);
    RtlPrintUnsigned64IntegerIntoUart("X5: ", frame->x5);
    RtlPrintUnsigned64IntegerIntoUart("X6: ", frame->x6);
    RtlPrintUnsigned64IntegerIntoUart("X7: ", frame->x7);
    RtlPrintUnsigned64IntegerIntoUart("X8: ", frame->x8);
    RtlPrintUnsigned64IntegerIntoUart("X9: ", frame->x9);
    RtlPrintUnsigned64IntegerIntoUart("X10: ", frame->x10);
    RtlPrintUnsigned64IntegerIntoUart("X11: ", frame->x11);
    RtlPrintUnsigned64IntegerIntoUart("X12: ", frame->x12);
    RtlPrintUnsigned64IntegerIntoUart("X13: ", frame->x13);
    RtlPrintUnsigned64IntegerIntoUart("X14: ", frame->x14);
    RtlPrintUnsigned64IntegerIntoUart("X15: ", frame->x15);
    RtlPrintUnsigned64IntegerIntoUart("X16: ", frame->x16);
    RtlPrintUnsigned64IntegerIntoUart("X17: ", frame->x17);
    RtlPrintUnsigned64IntegerIntoUart("X18: ", frame->x18);
    RtlPrintUnsigned64IntegerIntoUart("FP: ", frame->fp);
    RtlPrintUnsigned64IntegerIntoUart("LR: ", frame->lr);
    RtlPrintUnsigned64IntegerIntoUart("XZR: ", frame->xzr);
    RtlPrintUnsigned64IntegerIntoUart("ESR: ", frame->esr);
    RtlPrintUnsigned64IntegerIntoUart("FAR: ", frame->far);
}


void KeBugCheck(char* error){
    KiPrintStringToUart("BUGCHECK! SYSTEM HALTED!\n");
    KiPrintStringToUart(error);
    KiPrintStringToUart("\n\nDUMPING REGISTER INFORMATION\n\n");
    KiStartBugcheckRegisterDump();
    KiPrintStringToUart("\nSYSTEM HALTED\n");
    while(1){continue;}
}

void KiDumpRegistersToUart(){
    KiStartBugcheckRegisterDump();
}