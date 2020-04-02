	.file	"main.c"
	.text
	.globl	err_msg
	.data
	.align 32
err_msg:
	.ascii "T\0h\0e\0 \0o\0p\0e\0r\0a\0t\0i\0o\0n\0 \0c\0o\0m\0p\0l\0e\0t\0e\0d\0 \0s\0u\0c\0c\0e\0s\0s\0f\0u\0l\0l\0y\0.\0\0\0"
	.space 84
	.ascii "T\0h\0e\0 \0i\0m\0a\0g\0e\0 \0f\0a\0i\0l\0e\0d\0 \0t\0o\0 \0l\0o\0a\0d\0.\0\0\0"
	.space 108
	.ascii "A\0 \0p\0a\0r\0a\0m\0e\0t\0e\0r\0 \0w\0a\0s\0 \0i\0n\0c\0o\0r\0r\0e\0c\0t\0.\0\0\0"
	.space 106
	.ascii "T\0h\0e\0 \0o\0p\0e\0r\0a\0t\0i\0o\0n\0 \0i\0s\0 \0n\0o\0t\0 \0s\0u\0p\0p\0o\0r\0t\0e\0d\0.\0\0\0"
	.space 96
	.ascii "T\0h\0e\0 \0b\0u\0f\0f\0e\0r\0 \0w\0a\0s\0 \0n\0o\0t\0 \0t\0h\0e\0 \0p\0r\0o\0p\0e\0r\0 \0s\0i\0z\0e\0 \0f\0o\0r\0 \0t\0h\0e\0 \0r\0e\0q\0u\0e\0s\0t\0.\0\0\0"
	.space 56
	.ascii "T\0h\0e\0 \0b\0u\0f\0f\0e\0r\0 \0i\0s\0 \0n\0o\0t\0 \0l\0a\0r\0g\0e\0 \0e\0n\0o\0u\0g\0h\0 \0t\0o\0 \0h\0o\0l\0d\0 \0t\0h\0e\0 \0r\0e\0q\0u\0e\0s\0t\0e\0d\0 \0d\0a\0t\0a\0.\0\0\0"
	.space 42
	.ascii "T\0h\0e\0r\0e\0 \0i\0s\0 \0n\0o\0 \0d\0a\0t\0a\0 \0p\0e\0n\0d\0i\0n\0g\0 \0u\0p\0o\0n\0 \0r\0e\0t\0u\0r\0n\0.\0\0\0"
	.space 84
	.ascii "T\0h\0e\0 \0p\0h\0y\0s\0i\0c\0a\0l\0 \0d\0e\0v\0i\0c\0e\0 \0r\0e\0p\0o\0r\0t\0e\0d\0 \0a\0n\0 \0e\0r\0r\0o\0r\0 \0w\0h\0i\0l\0e\0 \0a\0t\0t\0e\0m\0p\0t\0i\0n\0g\0 \0t\0h\0e\0 \0o\0p\0e\0r\0a\0t\0i\0o\0n\0.\0\0\0"
	.space 20
	.space 4480
	.globl	gEfiSimpleTextOutputProtocolGuid
	.align 16
gEfiSimpleTextOutputProtocolGuid:
	.long	947156930
	.word	27079
	.word	4562
	.byte	-114
	.byte	57
	.byte	0
	.byte	-96
	.byte	-55
	.byte	105
	.byte	114
	.byte	59
	.globl	gST
	.bss
	.align 8
gST:
	.space 8
	.globl	gBS
	.align 8
gBS:
	.space 8
	.globl	gRS
	.align 8
gRS:
	.space 8
	.text
	.globl	initGlobal
	.def	initGlobal;	.scl	2;	.type	32;	.endef
	.seh_proc	initGlobal
initGlobal:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, gST(%rip)
	movq	gST(%rip), %rax
	movq	96(%rax), %rax
	movq	%rax, gBS(%rip)
	movq	gST(%rip), %rax
	movq	88(%rax), %rax
	movq	%rax, gRS(%rip)
	movl	$0, %eax
	popq	%rbp
	ret
	.seh_endproc
	.globl	gEfiLoadedImageProtocolGuid
	.data
	.align 16
gEfiLoadedImageProtocolGuid:
	.long	1528508833
	.word	-27294
	.word	4562
	.byte	-114
	.byte	63
	.byte	0
	.byte	-96
	.byte	-55
	.byte	105
	.byte	114
	.byte	59
	.globl	gEfiSimpleFileSystemProtocolGuid
	.align 16
gEfiSimpleFileSystemProtocolGuid:
	.long	-1773249758
	.word	25689
	.word	4562
	.byte	-114
	.byte	57
	.byte	0
	.byte	-96
	.byte	-55
	.byte	105
	.byte	114
	.byte	59
	.globl	gEfiFileInfoGuid
	.align 16
gEfiFileInfoGuid:
	.long	156724882
	.word	27967
	.word	4562
	.byte	-114
	.byte	57
	.byte	0
	.byte	-96
	.byte	-55
	.byte	105
	.byte	114
	.byte	59
	.globl	gEfiGraphicsOutputProtocolGuid
	.align 16
gEfiGraphicsOutputProtocolGuid:
	.long	-1874679330
	.word	9180
	.word	19000
	.byte	-106
	.byte	-5
	.byte	122
	.byte	-34
	.byte	-48
	.byte	-128
	.byte	81
	.byte	106
	.section .rdata,"dr"
	.align 2
.LC0:
	.ascii "%\0c\0\0\0"
	.text
	.globl	printf
	.def	printf;	.scl	2;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$256, %rsp
	.seh_stackalloc	256
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, 144(%rbp)
	movq	%rdx, 152(%rbp)
	movq	%r8, 160(%rbp)
	movq	%r9, 168(%rbp)
	movl	$0, 108(%rbp)
	movw	$48, -96(%rbp)
	movw	$49, -94(%rbp)
	movw	$50, -92(%rbp)
	movw	$51, -90(%rbp)
	movw	$52, -88(%rbp)
	movw	$53, -86(%rbp)
	movw	$54, -84(%rbp)
	movw	$55, -82(%rbp)
	movw	$56, -80(%rbp)
	movw	$57, -78(%rbp)
	movw	$65, -76(%rbp)
	movw	$66, -74(%rbp)
	movw	$67, -72(%rbp)
	movw	$68, -70(%rbp)
	movw	$69, -68(%rbp)
	movw	$70, -66(%rbp)
	leaq	152(%rbp), %rax
	movq	%rax, -56(%rbp)
.L18:
	movq	144(%rbp), %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	cmpl	$37, %eax
	jne	.L4
	addq	$2, 144(%rbp)
	movq	144(%rbp), %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	cmpl	$100, %eax
	je	.L5
	cmpl	$100, %eax
	jg	.L6
	cmpl	$99, %eax
	je	.L7
	jmp	.L17
.L6:
	cmpl	$115, %eax
	je	.L9
	cmpl	$120, %eax
	je	.L10
	jmp	.L17
.L5:
	movq	$0, 120(%rbp)
	movq	-56(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	%rdx, -56(%rbp)
	movq	(%rax), %rax
	movq	%rax, 112(%rbp)
.L11:
	movq	112(%rbp), %rcx
	movabsq	$-3689348814741910323, %rdx
	movq	%rcx, %rax
	mulq	%rdx
	shrq	$3, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rax, %rax
	subq	%rax, %rcx
	movq	%rcx, %rdx
	movl	%edx, %ecx
	movq	120(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, 120(%rbp)
	leal	48(%rcx), %edx
	movw	%dx, -48(%rbp,%rax,2)
	movq	112(%rbp), %rax
	movabsq	$-3689348814741910323, %rdx
	mulq	%rdx
	movq	%rdx, %rax
	shrq	$3, %rax
	movq	%rax, 112(%rbp)
	cmpq	$0, 112(%rbp)
	jne	.L11
	jmp	.L12
.L13:
	movq	120(%rbp), %rax
	movzwl	-48(%rbp,%rax,2), %eax
	movzwl	%ax, %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
.L12:
	movq	120(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	%rdx, 120(%rbp)
	testq	%rax, %rax
	jne	.L13
	jmp	.L8
.L7:
	movq	-56(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	%rdx, -56(%rbp)
	movl	(%rax), %eax
	movw	%ax, 92(%rbp)
	movw	$0, 94(%rbp)
	movq	gST(%rip), %rax
	movq	64(%rax), %rax
	movq	8(%rax), %r8
	movq	gST(%rip), %rax
	movq	64(%rax), %rcx
	leaq	92(%rbp), %rax
	movq	%rax, %rdx
	call	*%r8
	jmp	.L8
.L10:
	movq	$0, 120(%rbp)
	movq	-56(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	%rdx, -56(%rbp)
	movq	(%rax), %rax
	movq	%rax, 112(%rbp)
.L14:
	movq	112(%rbp), %rax
	andl	$15, %eax
	movq	%rax, %rcx
	movq	120(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, 120(%rbp)
	movzwl	-96(%rbp,%rcx,2), %edx
	movw	%dx, -48(%rbp,%rax,2)
	movq	112(%rbp), %rax
	shrq	$4, %rax
	movq	%rax, 112(%rbp)
	cmpq	$0, 112(%rbp)
	jne	.L14
	jmp	.L15
.L16:
	movq	120(%rbp), %rax
	movzwl	-48(%rbp,%rax,2), %eax
	movzwl	%ax, %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
.L15:
	movq	120(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	%rdx, 120(%rbp)
	testq	%rax, %rax
	jne	.L16
	jmp	.L8
.L9:
	movq	-56(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	%rdx, -56(%rbp)
	movq	(%rax), %rax
	movq	%rax, 96(%rbp)
	movq	96(%rbp), %rax
	movq	%rax, %rcx
	call	printf
	nop
.L8:
	jmp	.L17
.L4:
	movq	144(%rbp), %rax
	movzwl	(%rax), %eax
	movw	%ax, 92(%rbp)
	movw	$0, 94(%rbp)
	movq	gST(%rip), %rax
	movq	64(%rax), %rax
	movq	8(%rax), %r8
	movq	gST(%rip), %rax
	movq	64(%rax), %rcx
	leaq	92(%rbp), %rax
	movq	%rax, %rdx
	call	*%r8
	nop
.L17:
	movq	144(%rbp), %rax
	leaq	2(%rax), %rdx
	movq	%rdx, 144(%rbp)
	movzwl	(%rax), %eax
	testw	%ax, %ax
	jne	.L18
	movl	108(%rbp), %eax
	addq	$256, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	strlen
	.def	strlen;	.scl	2;	.type	32;	.endef
	.seh_proc	strlen
strlen:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L21
.L22:
	addl	$1, -4(%rbp)
.L21:
	movq	16(%rbp), %rax
	leaq	2(%rax), %rdx
	movq	%rdx, 16(%rbp)
	movzwl	(%rax), %eax
	testw	%ax, %ax
	jne	.L22
	movl	-4(%rbp), %eax
	cltq
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC1:
	.ascii "[\0F\0a\0t\0a\0l\0]\0 \0G\0r\0a\0p\0h\0i\0c\0O\0u\0t\0p\0u\0t\0P\0r\0o\0t\0o\0c\0o\0l\0 \0L\0o\0c\0a\0t\0e\0 \0E\0r\0r\0o\0r\0 \0:\0 \0%\0s\0\15\0\12\0\0\0"
	.align 8
.LC2:
	.ascii "[\0I\0n\0f\0o\0]\0V\0R\0A\0M\0 \0:\0 \0"
	.ascii "0\0x\0%\0x\0\15\0\12\0\0\0"
	.align 8
.LC3:
	.ascii "[\0F\0a\0t\0a\0l\0]\0 \0O\0p\0e\0n\0 \0P\0r\0o\0t\0o\0c\0o\0l\0 \0o\0f\0 \0L\0o\0a\0d\0e\0d\0I\0m\0a\0g\0e\0 \0E\0r\0r\0o\0r\0 \0:\0 \0%\0s\0\15\0\12\0\0\0"
	.align 8
.LC4:
	.ascii "[\0F\0a\0t\0a\0l\0]\0 \0O\0p\0e\0n\0 \0P\0r\0o\0t\0o\0c\0o\0l\0 \0o\0f\0 \0S\0i\0m\0p\0l\0e\0F\0i\0l\0e\0S\0y\0s\0t\0e\0m\0 \0E\0r\0r\0o\0r\0 \0:\0 \0%\0d\0\15\0\12\0\0\0"
	.align 8
.LC5:
	.ascii "[\0F\0a\0t\0a\0l\0]\0 \0O\0p\0e\0n\0 \0V\0o\0l\0u\0m\0e\0 \0o\0f\0 \0r\0o\0o\0t\0 \0E\0r\0r\0o\0r\0 \0:\0 \0%\0d\0\15\0\12\0\0\0"
	.align 2
.LC6:
	.ascii "\\\0k\0e\0r\0n\0e\0l\0.\0b\0i\0n\0\0\0"
	.align 8
.LC7:
	.ascii "[\0F\0a\0t\0a\0l\0]\0 \0K\0e\0r\0n\0e\0l\0 \0O\0p\0e\0n\0 \0E\0r\0r\0o\0r\0 \0:\0 \0%\0d\0\15\0\12\0\0\0"
	.align 8
.LC8:
	.ascii "[\0F\0a\0t\0a\0l\0]\0 \0G\0e\0t\0 \0K\0e\0r\0n\0e\0l\0 \0I\0n\0f\0o\0 \0E\0r\0r\0o\0r\0 \0:\0 \0%\0d\0\15\0\12\0\0\0"
	.align 8
.LC9:
	.ascii "S\0i\0z\0e\0 \0 \0 \0 \0 \0:\0 \0"
	.ascii "0\0x\0%\0x\0\15\0\12\0\0\0"
	.align 8
.LC10:
	.ascii "F\0i\0l\0e\0S\0i\0z\0e\0 \0:\0 \0"
	.ascii "0\0x\0%\0x\0\15\0\12\0\0\0"
	.align 8
.LC11:
	.ascii "F\0i\0l\0e\0N\0a\0m\0e\0 \0:\0 \0%\0s\0\15\0\12\0\0\0"
	.align 8
.LC12:
	.ascii "[\0F\0a\0t\0a\0l\0]\0 \0K\0e\0r\0n\0e\0l\0 \0H\0e\0a\0d\0e\0r\0 \0R\0e\0a\0d\0 \0E\0r\0r\0o\0r\0 \0:\0 \0%\0d\0\15\0\12\0\0\0"
	.align 8
.LC13:
	.ascii "[\0F\0a\0t\0a\0l\0]\0 \0K\0e\0r\0n\0e\0l\0 \0M\0a\0i\0n\0 \0R\0e\0a\0d\0 \0E\0r\0r\0o\0r\0 \0:\0 \0%\0d\0\15\0\12\0\0\0"
	.align 8
.LC14:
	.ascii "[\0I\0n\0f\0o\0]\0K\0e\0r\0n\0e\0l\0(\0B\0u\0f\0f\0e\0r\0 \0:\0 \0"
	.ascii "0\0x\0%\0x\0)\0 \0:\0 \0\0\0"
	.align 2
.LC15:
	.ascii "%\0x\0 \0\0\0"
	.align 8
.LC16:
	.ascii "[\0F\0a\0t\0a\0l\0]\0 \0K\0e\0r\0n\0e\0l\0 \0C\0l\0o\0s\0e\0 \0E\0r\0r\0o\0r\0 \0:\0 \0%\0s\0\15\0\12\0\0\0"
	.align 8
.LC17:
	.ascii "[\0I\0n\0f\0o\0]\0S\0y\0s\0t\0e\0m\0T\0a\0b\0l\0e\0 \0:\0 \0"
	.ascii "0\0x\0%\0x\0\15\0\12\0\0\0"
	.align 8
.LC18:
	.ascii "[\0I\0n\0f\0o\0]\0K\0e\0r\0n\0e\0l\0(\0M\0e\0m\0o\0r\0y\0 \0:\0 \0"
	.ascii "0\0x\0%\0x\0)\0 \0:\0 \0\0\0"
	.align 8
.LC19:
	.ascii "[\0I\0n\0f\0o\0]\0 \0N\0u\0m\0b\0e\0r\0 \0O\0f\0 \0B\0o\0o\0t\0 \0:\0 \0%\0d\0\15\0\12\0\0\0"
	.align 8
.LC20:
	.ascii "[\0I\0n\0f\0o\0]\0 \0G\0e\0t\0M\0e\0m\0o\0r\0y\0M\0a\0p\0 \0:\0 \0%\0s\0(\0%\0d\0)\0\15\0\12\0\0\0"
	.align 8
.LC21:
	.ascii "m\0e\0m\0o\0r\0y\0M\0a\0p\0 \0:\0 \0"
	.ascii "0\0x\0%\0x\0\15\0\12\0\0\0"
	.align 8
.LC22:
	.ascii "m\0a\0p\0S\0i\0z\0e\0 \0 \0 \0:\0 \0"
	.ascii "0\0x\0%\0x\0\15\0\12\0\0\0"
	.align 8
.LC23:
	.ascii "m\0a\0p\0K\0e\0y\0 \0 \0 \0 \0:\0 \0"
	.ascii "0\0x\0%\0x\0\15\0\12\0\0\0"
	.align 8
.LC24:
	.ascii "[\0F\0a\0t\0a\0l\0]\0 \0E\0x\0i\0t\0B\0o\0o\0t\0S\0e\0r\0v\0i\0c\0e\0s\0 \0:\0 \0%\0s\0(\0%\0d\0)\0\15\0\12\0\0\0"
	.text
	.globl	efiMain
	.def	efiMain;	.scl	2;	.type	32;	.endef
	.seh_proc	efiMain
efiMain:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$504, %rsp
	.seh_stackalloc	504
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, 432(%rbp)
	movq	%rdx, 440(%rbp)
	movq	440(%rbp), %rax
	movq	%rax, %rcx
	call	initGlobal
	movq	440(%rbp), %rax
	movq	64(%rax), %rax
	movq	48(%rax), %rax
	movq	440(%rbp), %rdx
	movq	64(%rdx), %rdx
	movq	%rdx, %rcx
	call	*%rax
	movq	%rax, 352(%rbp)
	movq	$0, 272(%rbp)
	movq	$1048576, 336(%rbp)
	movq	gBS(%rip), %rax
	movq	320(%rax), %rax
	leaq	272(%rbp), %rdx
	movq	%rdx, %r8
	movl	$0, %edx
	leaq	gEfiGraphicsOutputProtocolGuid(%rip), %rcx
	call	*%rax
	movq	%rax, 352(%rbp)
	cmpq	$0, 352(%rbp)
	je	.L25
	movq	352(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$5, %rax
	leaq	err_msg(%rip), %rdx
	addq	%rdx, %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	printf
.L26:
	jmp	.L26
.L25:
	movl	$91, %ecx
	call	putchar
	movq	272(%rbp), %rax
	movq	24(%rax), %rax
	movq	24(%rax), %rax
	movq	%rax, %rdx
	movq	336(%rbp), %rax
	movq	%rdx, (%rax)
	movq	272(%rbp), %rax
	movq	24(%rax), %rax
	movq	8(%rax), %rax
	movl	4(%rax), %eax
	movl	%eax, %edx
	movq	336(%rbp), %rax
	movw	%dx, 8(%rax)
	movq	272(%rbp), %rax
	movq	24(%rax), %rax
	movq	8(%rax), %rax
	movl	8(%rax), %eax
	movl	%eax, %edx
	movq	336(%rbp), %rax
	movw	%dx, 10(%rax)
	movq	336(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rcx
	call	printf
	movq	$0, 264(%rbp)
	movq	gBS(%rip), %rax
	movq	280(%rax), %rax
	leaq	248(%rbp), %rdx
	movl	$2, 40(%rsp)
	movq	$0, 32(%rsp)
	movq	432(%rbp), %r9
	movq	%rdx, %r8
	leaq	gEfiLoadedImageProtocolGuid(%rip), %rdx
	movq	432(%rbp), %rcx
	call	*%rax
	movq	%rax, 352(%rbp)
	cmpq	$0, 352(%rbp)
	je	.L27
	movq	352(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$5, %rax
	leaq	err_msg(%rip), %rdx
	addq	%rdx, %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rcx
	call	printf
	movq	352(%rbp), %rax
	jmp	.L49
.L27:
	movl	$91, %ecx
	call	putchar
	movq	gBS(%rip), %rax
	movq	280(%rax), %rax
	movq	248(%rbp), %rdx
	movq	24(%rdx), %rcx
	leaq	256(%rbp), %rdx
	movl	$2, 40(%rsp)
	movq	$0, 32(%rsp)
	movq	432(%rbp), %r9
	movq	%rdx, %r8
	leaq	gEfiSimpleFileSystemProtocolGuid(%rip), %rdx
	call	*%rax
	movq	%rax, 352(%rbp)
	cmpq	$0, 352(%rbp)
	je	.L29
	movq	352(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rcx
	call	printf
	movq	352(%rbp), %rax
	jmp	.L49
.L29:
	movl	$91, %ecx
	call	putchar
	movq	256(%rbp), %rax
	movq	8(%rax), %r8
	movq	256(%rbp), %rcx
	leaq	264(%rbp), %rax
	movq	%rax, %rdx
	call	*%r8
	movq	%rax, 352(%rbp)
	cmpq	$0, 352(%rbp)
	je	.L30
	movq	352(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC5(%rip), %rcx
	call	printf
	movq	352(%rbp), %rax
	jmp	.L49
.L30:
	movl	$91, %ecx
	call	putchar
	leaq	.LC6(%rip), %rax
	movq	%rax, 328(%rbp)
	movq	264(%rbp), %rax
	movq	8(%rax), %r10
	movq	264(%rbp), %rcx
	movq	328(%rbp), %rdx
	leaq	240(%rbp), %rax
	movq	$0, 32(%rsp)
	movl	$1, %r9d
	movq	%rdx, %r8
	movq	%rax, %rdx
	call	*%r10
	movq	%rax, 352(%rbp)
	cmpq	$0, 352(%rbp)
	je	.L31
	movq	352(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC7(%rip), %rcx
	call	printf
	movq	352(%rbp), %rax
	jmp	.L49
.L31:
	movl	$91, %ecx
	call	putchar
	movq	328(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	addq	$41, %rax
	addq	%rax, %rax
	movq	%rax, 232(%rbp)
	movq	232(%rbp), %rax
	movq	%rsp, %rdx
	movq	%rdx, %rbx
	movq	%rax, %rdx
	subq	$1, %rdx
	movq	%rdx, 320(%rbp)
	movq	%rax, %r12
	movl	$0, %r13d
	movq	%rax, %rsi
	movl	$0, %edi
	addq	$15, %rax
	shrq	$4, %rax
	salq	$4, %rax
	call	___chkstk_ms
	subq	%rax, %rsp
	leaq	48(%rsp), %rax
	addq	$0, %rax
	movq	%rax, 312(%rbp)
	movq	240(%rbp), %rax
	movq	64(%rax), %rax
	movq	312(%rbp), %r8
	movq	240(%rbp), %rcx
	leaq	232(%rbp), %rdx
	movq	%r8, %r9
	movq	%rdx, %r8
	leaq	gEfiFileInfoGuid(%rip), %rdx
	call	*%rax
	movq	%rax, 352(%rbp)
	cmpq	$0, 352(%rbp)
	je	.L32
	movq	352(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC8(%rip), %rcx
	call	printf
	movq	352(%rbp), %rax
	jmp	.L33
.L32:
	movq	312(%rbp), %rax
	movq	%rax, 304(%rbp)
	movl	$45, %ecx
	call	putchar
	movq	304(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	leaq	.LC9(%rip), %rcx
	call	printf
	movq	304(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	printf
	movq	304(%rbp), %rax
	addq	$80, %rax
	movq	%rax, %rdx
	leaq	.LC11(%rip), %rcx
	call	printf
	movq	$0, 296(%rbp)
	movq	304(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, 224(%rbp)
	movq	$256, -40(%rbp)
	movq	240(%rbp), %rax
	movq	32(%rax), %r9
	movq	240(%rbp), %rcx
	leaq	-32(%rbp), %rdx
	leaq	-40(%rbp), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	call	*%r9
	movq	%rax, 352(%rbp)
	cmpq	$0, 352(%rbp)
	je	.L34
	movq	352(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rcx
	call	printf
	movq	352(%rbp), %rax
	jmp	.L33
.L34:
	movl	$91, %ecx
	call	putchar
	movq	224(%rbp), %rdx
	movq	-40(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, 224(%rbp)
	movq	$0, 288(%rbp)
	movq	240(%rbp), %rax
	movq	32(%rax), %r9
	movq	240(%rbp), %rcx
	movq	288(%rbp), %rdx
	leaq	224(%rbp), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	call	*%r9
	movq	%rax, 352(%rbp)
	cmpq	$0, 352(%rbp)
	je	.L35
	movq	352(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC13(%rip), %rcx
	call	printf
	movq	352(%rbp), %rax
	jmp	.L33
.L35:
	movl	$91, %ecx
	call	putchar
	movq	288(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC14(%rip), %rcx
	call	printf
	movq	288(%rbp), %rax
	movq	%rax, 344(%rbp)
	movq	$0, 360(%rbp)
	jmp	.L36
.L37:
	movq	344(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, 344(%rbp)
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %edx
	leaq	.LC15(%rip), %rcx
	call	printf
	addq	$1, 360(%rbp)
.L36:
	cmpq	$15, 360(%rbp)
	jbe	.L37
	movl	$13, %ecx
	call	putchar
	movq	$1114112, 280(%rbp)
	movq	gBS(%rip), %rax
	movq	352(%rax), %rax
	movq	224(%rbp), %r8
	movq	288(%rbp), %rdx
	movq	280(%rbp), %rcx
	call	*%rax
	movl	$91, %ecx
	call	putchar
	movq	240(%rbp), %rax
	movq	16(%rax), %rax
	movq	240(%rbp), %rdx
	movq	%rdx, %rcx
	call	*%rax
	movq	%rax, 352(%rbp)
	cmpq	$0, 352(%rbp)
	je	.L38
	movq	352(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$5, %rax
	leaq	err_msg(%rip), %rdx
	addq	%rdx, %rax
	movq	%rax, %rdx
	leaq	.LC16(%rip), %rcx
	call	printf
	movq	352(%rbp), %rax
	jmp	.L33
.L38:
	movl	$91, %ecx
	call	putchar
	movq	440(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC17(%rip), %rcx
	call	printf
	movl	$1114112, %edx
	leaq	.LC18(%rip), %rcx
	call	printf
	movq	$1114112, 344(%rbp)
	movq	$0, 360(%rbp)
	jmp	.L39
.L40:
	movq	344(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	%rdx, 344(%rbp)
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %edx
	leaq	.LC15(%rip), %rcx
	call	printf
	addq	$1, 360(%rbp)
.L39:
	cmpq	$15, 360(%rbp)
	jbe	.L40
	movl	$13, %ecx
	call	putchar
	movq	$0, 360(%rbp)
	jmp	.L41
.L47:
	movq	360(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC19(%rip), %rcx
	call	printf
	movq	$0, -48(%rbp)
	movq	$0, -56(%rbp)
	movq	$0, -80(%rbp)
	movq	gBS(%rip), %rax
	movq	56(%rax), %r10
	movq	-80(%rbp), %rcx
	leaq	-64(%rbp), %r9
	leaq	-56(%rbp), %r8
	leaq	-48(%rbp), %rax
	leaq	-68(%rbp), %rdx
	movq	%rdx, 32(%rsp)
	movq	%rcx, %rdx
	movq	%rax, %rcx
	call	*%r10
	movq	%rax, 352(%rbp)
	movq	352(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$5, %rax
	leaq	err_msg(%rip), %rdx
	addq	%rdx, %rax
	movq	352(%rbp), %rdx
	movq	%rdx, %r8
	movq	%rax, %rdx
	leaq	.LC20(%rip), %rcx
	call	printf
	jmp	.L42
.L44:
	movq	-80(%rbp), %rax
	testq	%rax, %rax
	je	.L43
	movq	gBS(%rip), %rax
	movq	72(%rax), %rax
	movq	-80(%rbp), %rdx
	movq	%rdx, %rcx
	call	*%rax
	movq	%rax, 352(%rbp)
.L43:
	movq	-48(%rbp), %rax
	addq	$4096, %rax
	movq	%rax, -48(%rbp)
	movq	gBS(%rip), %rax
	movq	64(%rax), %rax
	movq	-48(%rbp), %rdx
	leaq	-80(%rbp), %rcx
	movq	%rcx, %r8
	movl	$2, %ecx
	call	*%rax
	movq	%rax, 352(%rbp)
	movq	gBS(%rip), %rax
	movq	56(%rax), %r10
	movq	-80(%rbp), %rcx
	leaq	-64(%rbp), %r9
	leaq	-56(%rbp), %r8
	leaq	-48(%rbp), %rax
	leaq	-68(%rbp), %rdx
	movq	%rdx, 32(%rsp)
	movq	%rcx, %rdx
	movq	%rax, %rcx
	call	*%r10
	movq	%rax, 352(%rbp)
.L42:
	movq	352(%rbp), %rax
	movzbl	%al, %eax
	cmpq	$5, %rax
	je	.L44
	movl	$45, %ecx
	call	putchar
	movq	-80(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC21(%rip), %rcx
	call	printf
	movq	-48(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC22(%rip), %rcx
	call	printf
	movq	-56(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC23(%rip), %rcx
	call	printf
	movq	gBS(%rip), %rax
	movq	232(%rax), %rax
	movq	-56(%rbp), %rdx
	movq	432(%rbp), %rcx
	call	*%rax
	movq	%rax, 352(%rbp)
	cmpq	$0, 352(%rbp)
	je	.L45
	movq	352(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$5, %rax
	leaq	err_msg(%rip), %rdx
	addq	%rdx, %rax
	movq	352(%rbp), %rdx
	movq	%rdx, %r8
	movq	%rax, %rdx
	leaq	.LC24(%rip), %rcx
	call	printf
	jmp	.L46
.L45:
/APP
 # 202 "boot/main.c" 1
	jmp    *0x110000

 # 0 "" 2
/NO_APP
.L46:
	addq	$1, 360(%rbp)
.L41:
	cmpq	$9, 360(%rbp)
	jbe	.L47
	movl	$66, %ecx
	call	putchar
.L48:
	jmp	.L48
.L33:
	movq	%rbx, %rsp
.L49:
	leaq	376(%rbp), %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%r12
	popq	%r13
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	putchar;	.scl	2;	.type	32;	.endef
