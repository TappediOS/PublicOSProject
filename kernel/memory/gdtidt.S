	.file	"gdtidt.c"
	.text
	.globl	initGdt
	.def	initGdt;	.scl	2;	.type	32;	.endef
	.seh_proc	initGdt
initGdt:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	.refptr.GDT(%rip), %rax
	movq	(%rax), %rax
	movq	$0, (%rax)
	movq	.refptr.GDT(%rip), %rax
	movq	(%rax), %rax
	addq	$8, %rax
	movabsq	$49427445715107839, %rdx
	movq	%rdx, (%rax)
	movq	.refptr.GDT(%rip), %rax
	movq	(%rax), %rax
	addq	$16, %rax
	movabsq	$58426948388454399, %rcx
	movq	%rcx, (%rax)
	call	loadGdt
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	idtr
	.bss
	.align 16
idtr:
	.space 16
	.section .rdata,"dr"
.LC0:
	.ascii "asmEmptyHandler : %x\0"
.LC1:
	.ascii "asmKeyboardHandler : %x\0"
.LC2:
	.ascii "IDT[ 0] : %x %x %x\0"
.LC3:
	.ascii "IDT[33] : %x %x %x\0"
	.text
	.globl	initIdt
	.def	initIdt;	.scl	2;	.type	32;	.endef
	.seh_proc	initIdt
initIdt:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$344, %rsp
	.seh_stackalloc	344
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	$0, 204(%rbp)
	jmp	.L3
.L4:
	movq	.refptr.asmEmptyHandler(%rip), %rdx
	movq	.refptr.IDT(%rip), %rax
	movq	(%rax), %rcx
	movl	204(%rbp), %eax
	cltq
	salq	$4, %rax
	leaq	(%rcx,%rax), %rbx
	leaq	-80(%rbp), %rax
	movq	%rax, %rcx
	call	makeGateDescriptor
	movq	-80(%rbp), %rax
	movq	-72(%rbp), %rdx
	movq	%rax, (%rbx)
	movq	%rdx, 8(%rbx)
	addl	$1, 204(%rbp)
.L3:
	cmpl	$255, 204(%rbp)
	jle	.L4
	movq	.refptr.asmKeyboardHandler(%rip), %rdx
	movq	.refptr.IDT(%rip), %rax
	movq	(%rax), %rax
	leaq	528(%rax), %rbx
	leaq	-80(%rbp), %rax
	movq	%rax, %rcx
	call	makeGateDescriptor
	movq	-80(%rbp), %rax
	movq	-72(%rbp), %rdx
	movq	%rax, (%rbx)
	movq	%rdx, 8(%rbx)
	movq	.refptr.IDT(%rip), %rax
	movq	(%rax), %rax
	salq	$16, %rax
	orq	$4095, %rax
	movq	%rax, idtr(%rip)
	movq	.refptr.IDT(%rip), %rax
	movq	(%rax), %rax
	shrq	$48, %rax
	movq	%rax, 8+idtr(%rip)
/APP
 # 37 "memory\gdtidt.c" 1
	lidt idtr
 # 0 "" 2
/NO_APP
	movl	$0, 204(%rbp)
	jmp	.L5
.L6:
	movl	204(%rbp), %eax
	cltq
	movb	$0, -64(%rbp,%rax)
	addl	$1, 204(%rbp)
.L5:
	cmpl	$255, 204(%rbp)
	jle	.L6
	movq	.refptr.asmEmptyHandler(%rip), %rax
	movl	%eax, %edx
	leaq	-64(%rbp), %rax
	movl	%edx, %r8d
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rcx
	call	sprintf
	leaq	-64(%rbp), %rax
	movl	$16777215, %r9d
	movq	%rax, %r8
	movl	$95, %edx
	movl	$20, %ecx
	call	drawString
	movq	.refptr.asmKeyboardHandler(%rip), %rax
	movl	%eax, %edx
	leaq	-64(%rbp), %rax
	movl	%edx, %r8d
	leaq	.LC1(%rip), %rdx
	movq	%rax, %rcx
	call	sprintf
	leaq	-64(%rbp), %rax
	movl	$16777215, %r9d
	movq	%rax, %r8
	movl	$120, %edx
	movl	$20, %ecx
	call	drawString
	movq	.refptr.IDT(%rip), %rax
	movq	(%rax), %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %edx
	movq	.refptr.IDT(%rip), %rax
	movq	(%rax), %rax
	movzwl	6(%rax), %eax
	movzwl	%ax, %ecx
	movq	.refptr.IDT(%rip), %rax
	movq	(%rax), %rax
	movl	8(%rax), %r8d
	leaq	-64(%rbp), %rax
	movl	%edx, 32(%rsp)
	movl	%ecx, %r9d
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rcx
	call	sprintf
	leaq	-64(%rbp), %rax
	movl	$16777215, %r9d
	movq	%rax, %r8
	movl	$140, %edx
	movl	$20, %ecx
	call	drawString
	movq	.refptr.IDT(%rip), %rax
	movq	(%rax), %rax
	addq	$528, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %edx
	movq	.refptr.IDT(%rip), %rax
	movq	(%rax), %rax
	addq	$528, %rax
	movzwl	6(%rax), %eax
	movzwl	%ax, %ecx
	movq	.refptr.IDT(%rip), %rax
	movq	(%rax), %rax
	addq	$528, %rax
	movl	8(%rax), %r8d
	leaq	-64(%rbp), %rax
	movl	%edx, 32(%rsp)
	movl	%ecx, %r9d
	leaq	.LC3(%rip), %rdx
	movq	%rax, %rcx
	call	sprintf
	leaq	-64(%rbp), %rax
	movl	$16777215, %r9d
	movq	%rax, %r8
	movl	$160, %edx
	movl	$20, %ecx
	call	drawString
	nop
	addq	$344, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC4:
	.ascii "initPIC master : %x\0"
	.text
	.globl	initPic
	.def	initPic;	.scl	2;	.type	32;	.endef
	.seh_proc	initPic
initPic:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$288, %rsp
	.seh_stackalloc	288
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	$255, %edx
	movl	$33, %ecx
	call	io_out8
	movl	$255, %edx
	movl	$161, %ecx
	call	io_out8
	movl	$17, %edx
	movl	$32, %ecx
	call	io_out8
	movl	$32, %edx
	movl	$33, %ecx
	call	io_out8
	movl	$4, %edx
	movl	$33, %ecx
	call	io_out8
	movl	$1, %edx
	movl	$33, %ecx
	call	io_out8
	movl	$17, %edx
	movl	$160, %ecx
	call	io_out8
	movl	$40, %edx
	movl	$161, %ecx
	call	io_out8
	movl	$2, %edx
	movl	$161, %ecx
	call	io_out8
	movl	$1, %edx
	movl	$161, %ecx
	call	io_out8
	movl	$251, %edx
	movl	$33, %ecx
	call	io_out8
	movl	$255, %edx
	movl	$161, %ecx
	call	io_out8
	movl	$161, %ecx
	call	io_in8
	movsbl	%al, %edx
	leaq	-96(%rbp), %rax
	movl	%edx, %r8d
	leaq	.LC4(%rip), %rdx
	movq	%rax, %rcx
	call	sprintf
	leaq	-96(%rbp), %rax
	movl	$16777215, %r9d
	movq	%rax, %r8
	movl	$75, %edx
	movl	$10, %ecx
	call	drawString
	nop
	addq	$288, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	makeGateDescriptor
	.def	makeGateDescriptor;	.scl	2;	.type	32;	.endef
	.seh_proc	makeGateDescriptor
makeGateDescriptor:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	24(%rbp), %rax
	movw	%ax, -16(%rbp)
	movw	$16, -14(%rbp)
	movzbl	-11(%rbp), %eax
	andl	$-16, %eax
	orl	$14, %eax
	movb	%al, -11(%rbp)
	movzbl	-11(%rbp), %eax
	orl	$-128, %eax
	movb	%al, -11(%rbp)
	movq	24(%rbp), %rax
	shrq	$16, %rax
	movw	%ax, -10(%rbp)
	movq	24(%rbp), %rax
	shrq	$32, %rax
	movl	%eax, -8(%rbp)
	movq	16(%rbp), %rcx
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	16(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	loadGdt;	.scl	2;	.type	32;	.endef
	.def	sprintf;	.scl	2;	.type	32;	.endef
	.def	drawString;	.scl	2;	.type	32;	.endef
	.def	io_out8;	.scl	2;	.type	32;	.endef
	.def	io_in8;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr.asmKeyboardHandler, "dr"
	.globl	.refptr.asmKeyboardHandler
	.linkonce	discard
.refptr.asmKeyboardHandler:
	.quad	asmKeyboardHandler
	.section	.rdata$.refptr.IDT, "dr"
	.globl	.refptr.IDT
	.linkonce	discard
.refptr.IDT:
	.quad	IDT
	.section	.rdata$.refptr.asmEmptyHandler, "dr"
	.globl	.refptr.asmEmptyHandler
	.linkonce	discard
.refptr.asmEmptyHandler:
	.quad	asmEmptyHandler
	.section	.rdata$.refptr.GDT, "dr"
	.globl	.refptr.GDT
	.linkonce	discard
.refptr.GDT:
	.quad	GDT
