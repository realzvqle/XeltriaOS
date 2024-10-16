.global KiJumpToUserMode

KiJumpToUserMode:
    stp x29, x30, [sp, #-16]!         
    
    ldr x0, =user_program_entry         
    msr ELR_EL1, x0                     
    mov x0, #0x000000C0                 
    msr SPSR_EL1, x0                    

    ldr x1, =user_stack_top             
    msr SP_EL0, x1                       
    ldp x29, x30, [sp], #16              
    eret           
    
                          

user_program_entry:
    bl UserModeInit
    b .
                            


.section .bss
.align 12
user_stack:
    .space 4096   

user_stack_top:                        
    .equ =user_stack + 4096 
