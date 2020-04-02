OUTPUT_ARCH(i386:x86-64);

MEMORY
{
    HEAD(rwx)  : ORIGIN = 0x00,  LENGTH = 0xFF
    BODY(rwx)  : ORIGIN = 0x100, LENGTH = 128m
}

SECTIONS
{
    .body : {
        QUAD(0x110010)
        *(.text)
        *(.rodata*)
        *(.data*)
        __bss_start = .;
        *(.bss)
        __bss_end = .;
    } > BODY
}
