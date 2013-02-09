CC = gcc -m32
CXX = g++ -m32 -std=c++11
CFLAGS = -Wall -Wextra -nostdlib -fno-builtin -nostartfiles -nodefaultlibs -fno-exceptions -fno-rtti -fno-stack-protector
LD = ld -melf_i386

OBJFILES = loader.o kmain.o Screen.o

all: kernel.bin

.s.o:
	nasm -f elf -o $@ $<

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

kernel.bin: $(OBJFILES)
	$(LD) -T linker.ld -o $@ $^

clean:
	$(RM) $(OBJFILES) kernel.bin kernel.img harddisk.img
