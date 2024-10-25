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
    b.eq error_ramfb
    bl KiEntry

    b .




error_ramfb:
    ldr x0, =error_message_ramfb
    bl KiSerialPrint
    b .


message:
    .asciz "Loading......\n"



error_message_ramfb:
    .asciz "The RamFB Driver Failed to Load, Make sure you have the device installed.\n"


