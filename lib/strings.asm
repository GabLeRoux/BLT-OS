%ifndef STRINGS
%define STRINGS

;%include "lib/strings_extensions.asm"

number_strings db 0

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

%endif
