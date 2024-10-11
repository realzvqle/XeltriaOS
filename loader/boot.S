.global _loader

_loader:
    ldr x30, =stack_beginning
    mov sp, x30
    ldr x0, =message
    bl KiSerialPrint
    bl KiInitializeHeap // creates the heap ahead of time, so by the time it loads KiEntry i don't need to call the heap there
    bl KiSetupFramebuffer // setups the framebuffer
    bl KiSetupRamFB
    mov x1, #1
    cmp x0, x1
    b.eq error
    bl KiEntry

    b .




error:
    ldr x0, =error_message
    bl KiSerialPrint
    b .


message:
    .asciz "Loading......\n"



error_message:
    .asciz "An Error Happened While Loading the System!\n"


