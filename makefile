SRC = $(shell find src -name "*.c")
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

all: arcos.iso

boot.o: boot.asm
	nasm -f elf32 boot.asm -o boot.o

build/%.o: src/%.c
	mkdir -p $(dir $@)
	gcc -m32 -ffreestanding -c $< -o $@

kernel.bin: boot.o $(OBJ)
	ld -m elf_i386 -T linker.ld -o kernel.bin boot.o $(OBJ)

arcos.iso: kernel.bin
	mkdir -p iso/boot/grub
	cp kernel.bin iso/boot/
	cp boot/grub/grub.cfg iso/boot/grub/
	grub-mkrescue -o arcos.iso iso

run: arcos.iso
	qemu-system-i386 -cdrom arcos.iso

clean:
	rm -rf build boot.o kernel.bin arcos.iso iso kernel.o