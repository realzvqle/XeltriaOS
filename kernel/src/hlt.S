.global KiHaltSystem


KiHaltSystem:
    stp x29, x30, [sp, #-16]!
    isb
loop:
    wfi
    b loop
    ldp x29, x30, [sp], #16  
    ret
