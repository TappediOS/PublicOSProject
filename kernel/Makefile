CFLAGS = -Wall -Wextra -O0 -nostdlib -fno-builtin -fno-common -e kernel_main
LDFLAGS = -T scripts/kernel.ld -e kernel_main

OBJS = kernel.obj

%.obj: %.c
	x86_64-w64-mingw32-gcc $< $(CFLAGS) -c -o $@

kernel.bin: $(OBJS)
	ld -Map kernel.map $(LDFLAGS) -o kernel.exe $+
	objcopy -O binary kernel.exe kernel.bin

clean:
	del kernel.bin
	del kernel.exe
	del kernel.map
	del $(OBJS)

