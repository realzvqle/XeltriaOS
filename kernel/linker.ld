ENTRY(_loader)
SECTIONS {
    . = 0x40100000; 
    .startup . : { boot.o(.text) }
    .text : { *(.text) }
    .data : { *(.data) }
    .bss : { *(.bss COMMON) }
    . = ALIGN(8);
    . += 0x100000; 
    stack_beginning = .;
}