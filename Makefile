###  Complie Option  ###
CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -Wextra -e efiMain -nostdlib -fno-builtin -Wl,--subsystem,10

###  Include Option  ###
iUEFI = -I src/uefi

###  Emulator Option  ###
QEMU = qemu-system-x86_64
BIOS = -bios tools/OVMF.fd
DRIVE = -drive file=fat:rw:image,format=raw

COPY = copy


main.efi: src/main.c Makefile
	$(CC) src/main.c -o main.efi $(iUEFI) $(CFLAGS)
	$(COPY) main.efi image\EFI\BOOT\BOOTX64.EFI

run:
	$(QEMU) $(BIOS) $(DRIVE)

