%include "lib/strings.asm"

disk_load:
    push dx
    
    mov ah, 0x02
    mov al, dh
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02
    int 0x13

    jc DISK_ERROR

    pop dx
    cmp dh, al
    jne DISK_ERROR
    ret

DISK_ERROR:
    mov si, DISK_ERROR_MESSAGE
    call print_string
    jmp $

DISK_ERROR_MESSAGE db "Erreur de lecture de disque...", 0
