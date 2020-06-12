# *****************************************
# 	kernel - Makefile
# 	Update  develop3.1
# *****************************************
CFLAGS = -Wall -Wextra -O0 -nodefaultlibs -nostdlib -fno-builtin -fno-common -e kernel_init -I include
LDFLAGS = -T scripts/kernel.ld

OBJS = 	console\console.obj	\
		core\entry.obj core\kernel.obj \
		device\mouse.obj \
		graphic\init.obj graphic\simple.obj graphic\string.obj \
		memory\asm_gdtidt.obj memory\gdtidt.obj memory\interrupt.obj memory\asm_interrupt.obj memory\device.obj \
		memory\asm_fault.obj memory\fault.obj memory\paging.obj \
		time\time.obj \
		util\asmfunc.obj util\stdio.obj util\fifo.obj

kernel.bin: $(OBJS) scripts\kernel.ld
	ld -Map kernel.map $(LDFLAGS) -o kernel.exe $+
	objcopy -O binary kernel.exe kernel.bin

%.obj: %.c
	x86_64-w64-mingw32-gcc $< $(CFLAGS) -c -o $@

%.obj: %.S
	nasm -felf64 $< -o $@

clean:
	del kernel.bin
	del kernel.exe
	del kernel.map
	del $(OBJS)
