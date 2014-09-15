[org 0x7c00]
[bits 16]
start:
mov si, message
call print_string
mainloop:
  mov si, prompt        ;Print prompt
  call print_string
  mov di, command       ;Move pointer to beginning of command
  read_command:
    mov ah, 0             ;Read input
    int 0x16
    cmp al, 13
    je return_pressed
    cmp al, 8
    je backspace_pressed 
    mov [di], al
    inc di
    mov ah, 0x0e
    int 0x10 
    jmp read_command
    return_pressed:
      mov ah, 0x0e
      int 0x10
      mov al, 10
      int 0x10
      mov ax, 0
      mov [di], ax
      jmp execute
    backspace_pressed:
      cmp di, command
      je read_command
      mov ah, 0x0e
      int 0x10
      mov al, 32
      int 0x10
      mov al, 8
      int 0x10
      dec di
      jmp read_command
  execute:
    mov si, command
    call split_strings
    mov si, test_command
    mov di, string_array0
    call compare_strings
    mov dh, [bool]
    cmp dh, 0
    je mainloop
      mov si, string_array1
      call print_string
      mov ah, 0x0e
      mov al, 10
      int 0x10
      mov al, 13
      int 0x10
  jmp mainloop

message db 'Welcome to my brand new OS!',10,13, 0
prompt db 'prompt>', 0
test_command db 'echo', 0
debug_OK db 'OK', 0
command times 50 db 0


%include "strings.asm"    

times 510-($-$$) db 0
dw 0xaa55
