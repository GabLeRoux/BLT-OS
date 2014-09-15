run: compile
	qemu boot.bin

compile: boot_sect.asm kernel.asm
	nasm boot_sect.asm -f bin -o boot_sect.bin
	nasm kernel.asm -f bin -o kernel.bin
	cat boot_sect.bin kernel.bin > boot.bin
