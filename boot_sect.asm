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
string_array0 times 15 db 0
string_array1 times 15 db 0
string_array2 times 15 db 0
string_array3 times 15 db 0
string_array4 times 15 db 0
number_strings db 0
bool db 0


;String printing procedure. Print the null-terminated string which offset is in SI.
print_string:
  pusha
  mov ah, 0x0e
  print_string_loop1:
  mov bx, [si]
  cmp bl, 0
  je end_print_string
  mov al, bl
  int 0x10
  add si, 1
  jmp print_string_loop1
  end_print_string:
  popa
  ret

;Compare strings in SI and DI
compare_strings:
  pusha
  compare_strings_loop1:
    mov ah, [si]
    mov al, [di]
    cmp ah, al
    je chars_equals
      mov bh, 0
      mov [bool], bh
      popa
      ret
    chars_equals:
      cmp ah, 0
      je strings_are_equals
        inc si
        inc di
        jmp compare_strings_loop1 
  strings_are_equals:
    mov bh, 1
    mov [bool], bh
    popa
    ret

;Split string in SI. Put strings in string_array strings. Put number of strings in number_strings 
split_strings:
  pusha
  mov cl, 0
  mov di, string_array0
  split_strings_loop1:
    mov bh, [si]
    cmp bh, ' '
    je space_found
    cmp bh, 0
    je eos_found
      ;mov si, debug_OK
      ;call print_string
      mov [di], bh
      inc di
      inc si
      jmp split_strings_loop1
    space_found:
      mov al, 0
      mov [di], al
      inc cl
      mov ax, 15
      mul cl
      add ax, string_array0
      mov di, ax
      inc si
      jmp split_strings_loop1
    eos_found:
      mov al, 0
      mov [di], al
      inc cl
      popa
      ret

    
  
    

times 510-($-$$) db 0
dw 0xaa55
