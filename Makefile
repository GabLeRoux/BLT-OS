run: compile
	qemu bin/boot.bin

compile: src/boot_sect.asm src/kernel.asm
	nasm src/boot_sect.asm -f bin -o bin/boot_sect.bin
	nasm src/kernel.asm -f bin -o bin/kernel.bin
	cat bin/boot_sect.bin bin/kernel.bin > bin/boot.bin
