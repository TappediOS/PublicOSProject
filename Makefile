###  Complie Option  ###
CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -Wextra -e efiMain -nostdlib -fno-builtin -Wl,--subsystem,10 -mno-stack-arg-probe

###  File List  ###
fUEFI 		= src/uefi/SystemStruct.h src/uefi/DType.h src/uefi/IOStruct.h src/uefi/FileStruct.h
fINCLUDE	= src/include/stdio.h src/include/string.h


###  Include Option  ###
iUEFI 		= -I src/uefi
iINCLUDE	= -I src/include

###  Emulator Option  ###
QEMU = qemu-system-x86_64
BIOS = -bios tools/OVMF.fd
DRIVE = -drive file=fat:rw:image,format=raw

COPY = copy


main.efi: src/main.c $(fUEFI) $(fINCLUDE) Makefile
	$(CC) src/main.c -o main.efi $(iUEFI) $(iINCLUDE) $(CFLAGS)
	$(COPY) main.efi image\EFI\BOOT\BOOTX64.EFI

run:
	$(QEMU) $(BIOS) $(DRIVE)

