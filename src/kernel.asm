[org 0x9000]
[bits 16]

kernel_main:
    mov si, message_test
    call print_string
    ret

%include "lib/strings.asm"

message_test db "testdemessage",0

times 5120-($-$$) db 0
