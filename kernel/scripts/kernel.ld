OUTPUT_ARCH(i386:x86-64);

MEMORY
{
    HEAD(rx) : ORIGIN = 0x000000, LENGTH = 990k
    BODY(rx) : ORIGIN = 0x110000, LENGTH = 128m
}

SECTIONS
{
    .body : {
        *(.text.entry )
        *(.text* )

        *(.rodata* )

        *(.data* )

        *(.rdata* )

        _bss_start = . ;
        *(.bss)
        _bss_end = .;

    } > BODY

    /DISCARD/ : {*(.eh_frame )}
}
