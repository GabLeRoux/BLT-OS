%ifndef SWITCH_TO_PM
%define SWITCH_TO_PM

[bits 16]

switch_to_pm:
    cli
    
    lgdt [gdt_descriptor]

    ;enable A20
    mov ax, 0x2401
    int 0x15

    cmp ah, 0
    jne ERROR_A20

    mov eax, cr0
    or eax, 0x1
    mov cr0, eax

    jmp CODE_SEG:init_pm

ERROR_A20:
    mov si, error_message_A20
    call print_string
    hlt

[bits 32]
init_pm:
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000
    mov esp, ebp

    mov ebx, my_message
    call print_string_pm

    call BEGIN_PM

my_message db "in init_pm",0
error_message_A20 db "ERROR A20 NOT ENABLED", 0

%endif
