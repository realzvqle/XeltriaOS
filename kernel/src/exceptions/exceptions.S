.global KiSetupExceptions



KiSetupExceptions:
    stp x29, x30, [sp, #-16]!
    adr x0, KiExceptionVectorTable
    msr VBAR_EL1, x0
    ldr x0, =exfinmessage
    bl KiPrintStringToUart
    ldp x29, x30, [sp], #16 
    ret


KiExceptionVectorTable:
    b .
.balign 0x80
    b .
.balign 0x80
    b .
.balign 0x80
    b .
.balign 0x80
    b KiInvalidExceptionEntry


KiInvalidExceptionEntry:
    ldr x0, =bugcheckmessage
    bl KeBugCheck
    eret

KiInvalidExceptionEntryBroken:
    // causes a memory leak in QEMU lol
    ldr x0, =bugcheckmessage
    // meant KeBugCheck but instead i wrote KiPrintStringToUart as a mistake
    // leading it to just continue after the exception
    bl KiPrintStringToUart
    eret

exfinmessage:
    .asciz "Finished Setting Up Exceptions"

bugcheckmessage:
    .asciz "SYSTEM_EXCEPTION"