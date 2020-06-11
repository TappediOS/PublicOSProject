%define _PML4 0x2000

global loadPageTable
loadPageTable:
    mov     rcx, _PML4
    or      rcx, 0x18   ; flag up pwt, pcd
    mov     cr3, rcx
    ret
