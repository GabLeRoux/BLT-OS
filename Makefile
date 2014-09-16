run: compile
	qemu bin/boot.bin

compile: src/boot_sect.asm src/kernel.c
	nasm src/boot_sect.asm -f bin -o bin/boot_sect.bin
	gcc -ffreestanding -c src/kernel.c -o bin/kernel.o
	ld -o bin/kernel.bin -Ttext 0x1000 bin/kernel.o --oformat binary
	cat bin/boot_sect.bin bin/kernel.bin padding > bin/boot.bin
