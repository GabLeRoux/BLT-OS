run: compile
	qemu boot_sect.bin

compile: boot_sect.asm
	nasm boot_sect.asm -f bin -o boot_sect.bin
