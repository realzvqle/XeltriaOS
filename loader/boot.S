.global _loader

_loader:
    ldr x30, =stack_beginning
    mov sp, x30
    bl KiEntry
    b .