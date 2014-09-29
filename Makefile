run: compile
	qemu bin/boot.bin

compile: src/boot_sect.asm src/kernel.c
	mkdir -p bin
	nasm src/boot_sect.asm -f bin -o bin/boot_sect.bin
	nasm src/kernel_entry.asm -f elf -o bin/kernel_entry.o
	gcc -m32 -ffreestanding -c src/kernel.c -o bin/kernel.o
	ld -m elf_i386 -o bin/kernel.bin -Ttext 0x1000 bin/kernel_entry.o bin/kernel.o --oformat binary
	cat bin/boot_sect.bin bin/kernel.bin padding > bin/boot.bin
