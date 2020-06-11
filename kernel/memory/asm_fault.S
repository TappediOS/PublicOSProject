; *************************************
;   memory - asm_fault.S
;   Update  develop4.0
; *************************************

extern emptyHandler
extern deHandler
extern dbHandler
extern nmiHandler
extern bpHandler
extern ofHandler
extern brHandler
extern udHandler
extern nmHandler
extern dfHandler
extern tsHandler
extern npHandler
extern ssHandler
extern gpHandler
extern pfHandler
extern mfHandler
extern acHandler
extern mcHandler
extern xmHandler


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

global asmDeHandler
asmDeHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    deHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmDbHandler
asmDbHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    dbHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmNmiHandler
asmNmiHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    nmiHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmBpHandler
asmBpHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    bpHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmOfHandler
asmOfHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    ofHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmBrHandler
asmBrHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    brHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmUdHandler
asmUdHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    udHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmNmHandler
asmNmHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    nmHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmDfHandler
asmDfHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    dfHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmTsHandler
asmTsHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    tsHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmNpHandler
asmNpHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    npHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmSsHandler
asmSsHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    ssHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmGpHandler
asmGpHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    gpHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmPfHandler
asmPfHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    pfHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmMfHandler
asmMfHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    mfHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmAcHandler
asmAcHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    acHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmMcHandler
asmMcHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    mcHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global asmXmHandler
asmXmHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    xmHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

