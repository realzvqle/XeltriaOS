.global _loader

_loader:
    ldr x30, =stack_beginning
    mov sp, x30
    bl KiInitializeHeap ; creates the heap ahead of time, so by the time it loads KiEntry i don't need to call the heap there
    bl KiEntry

    b .