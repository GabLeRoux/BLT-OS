#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "asm_io.h"

typedef enum{
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,

    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,

    KEY_ENTER,
    KEY_RSHIFT,
    KEY_LSHIFT,
    KEY_SPACE,
    KEY_BKSP,
    KEY_RCTRL,
    KEY_LCTRL,
    KEY_CAPS,
    KEY_RALT,
    KEY_LALT,
    KEY_ESC,

    KEY_F1,
    KEY_F2,
    KEY_F3,
    KEY_F4,
    KEY_F5,
    KEY_F6,
    KEY_F7,
    KEY_F8,
    KEY_F9,
    KEY_F10,
    KEY_F11,
    KEY_F12,

    KEY_UP,
    KEY_DOWN,
    KEY_RIGHT,
    KEY_LEFT,

    KEY_POUND,
    KEY_MINUS,
    KEY_EQUAL,
    KEY_LBRACKET,
    KEY_RBRACKET,
    KEY_SEMICOLON,
    KEY_BACKTICK,
    KEY_LESSTHAN,
    KEY_COMMA,
    KEY_DOT,

    KEY_NONE,
    KEY_UNKNOWN,
    MAX_KEY
} KEY;

typedef enum{UP, DOWN, UNKNOWN} KEY_STATUS;
typedef enum{PRESSED, RELEASED, NONE} KEY_EVENT;

char key_down[256] = {0};
KEY current_key;
KEY_EVENT current_event = NONE;
KEY_STATUS key_status = UP;

unsigned char get_key_scancode()
{
    return inb(0x60);
}

KEY get_key_symbol(unsigned char key)
{
    switch(key)
    {
        case 0x0b:
        {
            key_status = DOWN;
            return KEY_0;
        }
        case 0x8b:
        {
            key_status = UP;
            return KEY_0;
        }
        case 0x02:
        {
            key_status = DOWN;
            return KEY_1;
        }
        case 0x82:
        {
            key_status = UP;
            return KEY_1;
        }
        case 0x03:
        {
            key_status = DOWN;
            return KEY_2;
        }
        case 0x83:
        {
            key_status = UP;
            return KEY_2;
        }
        case 0x04:
        {
            key_status = DOWN;
            return KEY_3;
        }
        case 0x84:
        {
            key_status = UP;
            return KEY_3;
        }
        case 0x05:
        {
            key_status = DOWN;
            return KEY_4;
        }
        case 0x85:
        {
            key_status = UP;
            return KEY_4;
        }
        case 0x06:
        {
            key_status = DOWN;
            return KEY_5;
        }
        case 0x86:
        {
            key_status = UP;
            return KEY_5;
        }
        case 0x07:
        {
            key_status = DOWN;
            return KEY_6;
        }
        case 0x87:
        {
            key_status = UP;
            return KEY_6;
        }
        case 0x08:
        {
            key_status = DOWN;
            return KEY_7;
        }
        case 0x88:
        {
            key_status = UP;
            return KEY_7;
        }
        case 0x09:
        {
            key_status = DOWN;
            return KEY_8;
        }
        case 0x89:
        {
            key_status = UP;
            return KEY_8;
        }
        case 0x0a:
        {
            key_status = DOWN;
            return KEY_9;
        }
        case 0x8a:
        {
            key_status = UP;
            return KEY_9;
        }

        case 0x1e:
        {
            key_status = DOWN;
            return KEY_A;
        }
        case 0x9e:
        {
            key_status = UP;
            return KEY_A;
        }
        case 0x30:
        {
            key_status = DOWN;
            return KEY_B;
        }
        case 0xb0:
        {
            key_status = UP;
            return KEY_B;
        }
        case 0x2e:
        {
            key_status = DOWN;
            return KEY_C;
        }
        case 0xae:
        {
            key_status = UP;
            return KEY_C;
        }
        case 0x20:
        {
            key_status = DOWN;
            return KEY_D;
        }
        case 0xa0:
        {
            key_status = UP;
            return KEY_D;
        }
        case 0x12:
        {
            key_status = DOWN;
            return KEY_E;
        }
        case 0x92:
        {
            key_status = UP;
            return KEY_E;
        }
        case 0x21:
        {
            key_status = DOWN;
            return KEY_F;
        }
        case 0xa1:
        {
            key_status = UP;
            return KEY_F;
        }
        case 0x22:
        {
            key_status = DOWN;
            return KEY_G;
        }
        case 0xa2:
        {
            key_status = UP;
            return KEY_G;
        }
        case 0x23:
        {
            key_status = DOWN;
            return KEY_H;
        }
        case 0xa3:
        {
            key_status = UP;
            return KEY_H;
        }
        case 0x17:
        {
            key_status = DOWN;
            return KEY_I;
        }
        case 0x97:
        {
            key_status = UP;
            return KEY_I;
        }
        case 0x24:
        {
            key_status = DOWN;
            return KEY_J;
        }
        case 0xa4:
        {
            key_status = UP;
            return KEY_J;
        }
        case 0x25:
        {
            key_status = DOWN;
            return KEY_K;
        }
        case 0xa5:
        {
            key_status = UP;
            return KEY_K;
        }
        case 0x26:
        {
            key_status = DOWN;
            return KEY_L;
        }
        case 0xa6:
        {
            key_status = UP;
            return KEY_L;
        }
        case 0x32:
        {
            key_status = DOWN;
            return KEY_M;
        }
        case 0xb2:
        {
            key_status = UP;
            return KEY_M;
        }
        case 0x31:
        {
            key_status = DOWN;
            return KEY_N;
        }
        case 0xb1:
        {
            key_status = UP;
            return KEY_N;
        }
        case 0x18:
        {
            key_status = DOWN;
            return KEY_O;
        }
        case 0x98:
        {
            key_status = UP;
            return KEY_O;
        }
        case 0x19:
        {
            key_status = DOWN;
            return KEY_P;
        }
        case 0x99:
        {
            key_status = UP;
            return KEY_P;
        }
        case 0x10:
        {
            key_status = DOWN;
            return KEY_Q;
        }
        case 0x90:
        {
            key_status = UP;
            return KEY_Q;
        }
        case 0x13:
        {
            key_status = DOWN;
            return KEY_R;
        }
        case 0x93:
        {
            key_status = UP;
            return KEY_R;
        }
        case 0x1f:
        {
            key_status = DOWN;
            return KEY_S;
        }
        case 0x9f:
        {
            key_status = UP;
            return KEY_S;
        }
        case 0x14:
        {
            key_status = DOWN;
            return KEY_T;
        }
        case 0x94:
        {
            key_status = UP;
            return KEY_T;
        }
        case 0x16:
        {
            key_status = DOWN;
            return KEY_U;
        }
        case 0x96:
        {
            key_status = UP;
            return KEY_U;
        }
        case 0x2f:
        {
            key_status = DOWN;
            return KEY_V;
        }
        case 0xaf:
        {
            key_status = UP;
            return KEY_V;
        }
        case 0x11:
        {
            key_status = DOWN;
            return KEY_W;
        }
        case 0x91:
        {
            key_status = UP;
            return KEY_W;
        }
        case 0x2d:
        {
            key_status = DOWN;
            return KEY_X;
        }
        case 0xad:
        {
            key_status = UP;
            return KEY_X;
        }
        case 0x15:
        {
            key_status = DOWN;
            return KEY_Y;
        }
        case 0x95:
        {
            key_status = UP;
            return KEY_Y;
        }
        case 0x2c:
        {
            key_status = DOWN;
            return KEY_Z;
        }
        case 0xac:
        {
            key_status = UP;
            return KEY_Z;
        }

        case 0x1c:
        {
            key_status = DOWN;
            return KEY_ENTER;
        }
        case 0x9c:
        {
            key_status = UP;
            return KEY_ENTER;
        }
        case 0x0e:
        {
            key_status = DOWN;
            return KEY_BKSP;
        }
        case 0x8e:
        {
            key_status = UP;
            return KEY_BKSP;
        }

        default:
        {
            key_status = UNKNOWN;
            return KEY_UNKNOWN;
        }
    }
}

char key_sym_to_char(KEY key)
{
    switch(key)
    {
        case KEY_0: return '0';
        case KEY_1: return '1';
        case KEY_2: return '2';
        case KEY_3: return '3';
        case KEY_4: return '4';
        case KEY_5: return '5';
        case KEY_6: return '6';
        case KEY_7: return '7';
        case KEY_8: return '8';
        case KEY_9: return '9';

        case KEY_A: return 'a';
        case KEY_B: return 'b';
        case KEY_C: return 'c';
        case KEY_D: return 'd';
        case KEY_E: return 'e';
        case KEY_F: return 'f';
        case KEY_G: return 'g';
        case KEY_H: return 'h';
        case KEY_I: return 'i';
        case KEY_J: return 'j';
        case KEY_K: return 'k';
        case KEY_L: return 'l';
        case KEY_M: return 'm';
        case KEY_N: return 'n';
        case KEY_O: return 'o';
        case KEY_P: return 'p';
        case KEY_Q: return 'q';
        case KEY_R: return 'r';
        case KEY_S: return 's';
        case KEY_T: return 't';
        case KEY_U: return 'u';
        case KEY_V: return 'v';
        case KEY_W: return 'w';
        case KEY_X: return 'x';
        case KEY_Y: return 'y';
        case KEY_Z: return 'z';
        default: return KEY_UNKNOWN;
    }
}


void update_keyboard()
{
    unsigned char key_scancode = get_key_scancode();
    current_key = get_key_symbol(key_scancode); 
  
    current_event = NONE;

    if( key_status == UNKNOWN) return;
    else if( key_status == DOWN && key_down[current_key] == 0)
    {
        current_event = PRESSED;
        key_down[current_key] = 1;
    } 
    else if(key_status == UP && key_down[current_key] == 1)
    {
        current_event = RELEASED;
        key_down[current_key] = 0;
    }
}

char is_key_down(KEY key_symbol)
{
    return key_down[key_symbol];
}

char is_key_just_pressed(KEY key_symbol)
{
    if(current_key == key_symbol && current_event == PRESSED) return 1;
    else return 0;
}

char is_key_just_released(KEY key_symbol)
{
    if(current_key == key_symbol && current_event == RELEASED) return 1;
    else return 0;
}

char get_next_key_pressed()
{
    while(1)
    {
        update_keyboard();
        if(is_key_just_pressed(current_key)) return current_key;
    }
}


#endif
