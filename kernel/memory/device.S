	.file	"device.c"
	.text
	.globl	initTimer
	.def	initTimer;	.scl	2;	.type	32;	.endef
	.seh_proc	initTimer
initTimer:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$52, %edx
	movl	$67, %ecx
	call	io_out8
	movl	$156, %edx
	movl	$64, %ecx
	call	io_out8
	movl	$46, %edx
	movl	$64, %ecx
	call	io_out8
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "initialize Keyboard\0"
	.text
	.globl	initKeyBoard
	.def	initKeyBoard;	.scl	2;	.type	32;	.endef
	.seh_proc	initKeyBoard
initKeyBoard:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	waitKeyboardSendReady
	movl	$96, %edx
	movl	$100, %ecx
	call	io_out8
	call	waitKeyboardSendReady
	movl	$71, %edx
	movl	$96, %ecx
	call	io_out8
	movl	$16777215, %r9d
	leaq	.LC0(%rip), %r8
	movl	$55, %edx
	movl	$5, %ecx
	call	drawString
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	waitKeyboardSendReady
	.def	waitKeyboardSendReady;	.scl	2;	.type	32;	.endef
	.seh_proc	waitKeyboardSendReady
waitKeyboardSendReady:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
.L8:
	movl	$100, %ecx
	call	io_in8
	movsbl	%al, %eax
	andl	$2, %eax
	testl	%eax, %eax
	je	.L10
	jmp	.L8
.L10:
	nop
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	io_out8;	.scl	2;	.type	32;	.endef
	.def	drawString;	.scl	2;	.type	32;	.endef
	.def	io_in8;	.scl	2;	.type	32;	.endef
