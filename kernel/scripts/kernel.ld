OUTPUT_ARCH(i386:x86-64);
ENTRY(_start)

MEMORY
{
    HEAD(rx) : ORIGIN = 0x000000, LENGTH = 900k
    BODY(rx) : ORIGIN = 0x110000, LENGTH = 128m
}

SECTIONS
{
    .body : {
        *(.text.top )
        *(.text*)

        *(.rodata* )

        *(.data* )
        
        *(.rdata* )

        _bss_start = . ;
        *(.bss)
        _bss_end = . ;

    } > BODY
    
    /DISCARD/ : {*(.eh_frame)}
}
