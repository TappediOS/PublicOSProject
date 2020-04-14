; *******************************************
;   core - entry.S
;   Update  develop3.0
; *******************************************

extern kernel_init
global _start

[section .text.entry ]

_start:
    DQ  kernel_init

[section .text ]
