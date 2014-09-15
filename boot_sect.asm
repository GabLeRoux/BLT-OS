[org 0x7c00]
[bits 16]
start:
    mov [BOOT_DRIVE], dl

    mov bp, 0x8000
    mov sp, bp

    mov bx, 0x9000
    mov dh, 10
    mov dl, [BOOT_DRIVE]
    call disk_load

    call 0x9000

    jmp $ 

%include "lib/disk_load.asm"

message db "test", 0
BOOT_DRIVE db 0
  
times 510-($-$$) db 0
dw 0xaa55


