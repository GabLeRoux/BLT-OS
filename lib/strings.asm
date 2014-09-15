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


