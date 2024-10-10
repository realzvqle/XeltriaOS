.global test



test:
    stp x29, x30, [sp, #-16]!
    ldr x0, =message
    bl KiSerialPrint
    ldp x29, x30, [sp], #16  
    ret


message:
    .asciz "Loaded System, Assembly Files Work Too =3\n"


