.global KiCheckSystemIntegrity




KiCheckSystemIntegrity:
    stp x29, x30, [sp, #-16]!
    ldr x0, =message
    bl KiPanic
    ldp x29, x30, [sp], #16  
    ret





message:
    .asciz "System Error\n"
