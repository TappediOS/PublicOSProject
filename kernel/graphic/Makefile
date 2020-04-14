# **********************************
# 	graphic - Makefile
# 	Update  develop3.0
# **********************************

CFLAGS = -Wall -Wextra -O0 -nostdlib -fno-builtin -fno-common

%.obj: %.c
	x86_64-w64-mingw32-gcc $< $(CFLAGS) -c -o $@

%.obj: %.S
	nasm -felf64 $< -o $@

