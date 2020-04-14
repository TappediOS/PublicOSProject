; ************************************
;   memory - asm_interrupt.S
;   Update  develop3.0
; ************************************

extern emptyHandler
extern timerHandler
extern keyboardHandler

global asmEmptyHandler
asmEmptyHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    emptyHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmKeyboardHandler
asmKeyboardHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbx
    push    rbp
    push    rsi
    push    rdi
    call    keyboardHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rbx
    pop     rdx
    pop     rcx
    pop     rax
    iretq


loop_hlt:
    hlt
    jmp     loop_hlt
