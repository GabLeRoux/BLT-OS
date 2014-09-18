#include "screen.h"
#include "keyboard.h"
#include "strings.h"
#include "memory.h"

void main()
{
    
    clear();
    print_string("OK\n");
    print_int(99499);
    print_char('\n');
    print_int(67111);
    print_char('\n');
    char* test = "test";
    int lala = 50;
    char output[lala];
    print_string("fin");
    /*
    while(1)
    {
        if(*get_key_string() == 'a')
        {
            print_string("yes!\n");
            break;
        }
    }
    */
}
