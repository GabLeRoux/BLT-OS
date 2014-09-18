[org 0x7c00]
boot:
    KERNEL_OFFSET equ 0x1000

    mov [BOOT_DRIVE], dl

    mov bp, 0x9000
    mov sp, bp

    mov si, message2
    call print_string

    mov ah, 0x01
    mov cx, 0x2607
    int 0x10

    call load_kernel

    call switch_to_pm

    jmp $

%include "lib/disk_load.asm"
%include "lib/gdt.asm"
%include "lib/pm_print.asm"
%include "lib/switch_to_pm.asm"

[bits 16]
load_kernel:
    mov si, load_message
    call print_string

    mov bx, KERNEL_OFFSET
    mov dh, 50
    mov dl, [BOOT_DRIVE]
    call disk_load

    ret

[bits 32]
BEGIN_PM:
    mov ebx, message
    call print_string_pm

    call KERNEL_OFFSET

    jmp $

BOOT_DRIVE db 0
message db "It's working FUCKING GREAT",0
message2 db "In real mode...", 0
load_message db "Loading kernel...", 0
 
times 510-($-$$) db 0
dw 0xaa55


