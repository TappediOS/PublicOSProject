; *****************************************
;   memory - gdtidt.S
;   Update  develop3.0
; *****************************************

%define _GDT    0x0900
%define _GDTR   0x0010

%define _IDT    0x1000
%define _IDTR   0x0010

%define PML4T   0x2000;

extern kernel_main

section .text

global loadGdt
global main_label
global loadIdt
global setPaging


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

setPaging:
    mov     rax, PML4T
    mov     cr3, rax

    mov     rcx, 0xC0000080
    rdmsr
    or      rax, 1 << 8
    wrmsr

    mov     rax, cr0
    or      rax, 1 << 31 | 1 << 0
    mov     cr0, rax
    ret


