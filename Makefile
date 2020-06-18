###  Complie Option  ###
CC = x86_64-w64-mingw32-gcc
CFLAGS = -O0 -Wall -Wextra -e efiMain -nostdlib -fno-builtin -Wl,--subsystem,10 -mno-stack-arg-probe

###  File List  ###
fUEFI 		= boot/uefi/SystemStruct.h boot/uefi/DType.h boot/uefi/IOStruct.h boot/uefi/FileStruct.h boot/uefi/GraphicStruct.h
fINCLUDE	= boot/include/stdio.h boot/include/string.h


###  Include Option  ###
iUEFI 		= -I boot/uefi
iINCLUDE	= -I boot/include

###  Emulator Option  ###
QEMU = qemu-system-x86_64
BIOS = -bios tools/OVMF.fd
DRIVE = -drive if=pflash,format=raw,readonly,file=tools\OVMF.fd fat:rw:image
DEVICE = -device ahci,id=ahci -device ide-drive,drive=sata,bus=ahci.0 -drive if=none,id=sata,file=tools\hdd.img
MEMORY = -m 6G
RTC = -rtc base=localtime

COPY = copy

copy: kernel/kernel.bin
	$(COPY) kernel\kernel.bin image

main.efi: boot/main.c $(fUEFI) $(fINCLUDE) Makefile
	$(CC) boot/main.c -o main.efi $(iUEFI) $(iINCLUDE) $(CFLAGS)
	$(COPY) main.efi image\EFI\BOOT\BOOTX64.EFI

run:
	$(COPY) kernel\kernel.bin image
	$(QEMU) $(BIOS) $(DRIVE) $(DEVICE) $(MEMORY) $(RTC)

