; ************************************
;  entry.s
;  Update  develop2.1
; ************************************

extern kernel_main
global _start

[section .text.top]

_start:
    DQ  kernel_main

[section .text]
