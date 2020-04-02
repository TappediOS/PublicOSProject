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
DRIVE = -drive file=fat:rw:image,format=raw

COPY = copy


main.efi: boot/main.c $(fUEFI) $(fINCLUDE) Makefile
	$(CC) boot/main.c -o main.efi $(iUEFI) $(iINCLUDE) $(CFLAGS)
	$(COPY) main.efi image\EFI\BOOT\BOOTX64.EFI

run:
	$(QEMU) $(BIOS) $(DRIVE)

