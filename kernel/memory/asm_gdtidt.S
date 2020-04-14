; *****************************************
;   memory - gdtidt.S
;   Update  develop3.0
; *****************************************

%define _GDT    0x0080
%define _GDTR   0x0010

%define _IDT    0x13000
%define _IDTR   0x0010

extern kernel_main

section .text

global loadGdt
global main_label
global loadIdt


loadGdt:
    cli
    ; set GDT
    mov     [_GDTR],     word  0x18
    mov     [_GDTR + 2], dword _GDT
    lgdt    [_GDTR]

    ; set Segment Register
    mov     ax, 2 * 8
    mov     ds, ax
    mov     es, ax
    mov     ss, ax
    mov     gs, ax
    mov     fs, ax

    ; jmp kernel_main
    mov     rcx, rsp
    push    0x00
    push    rcx
    pushfq
    push    1 * 8
    push    main_label
    iretq

main_label:
    sti
    call    kernel_main

loadIdt:
    mov     word  [_IDTR],     word  16 * 256 - 1
    mov     qword [_IDTR + 2], qword _IDT
    lidt    [_IDTR]
    ret


