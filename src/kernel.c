#include "screen.h"
#include "keyboard.h"
#include "strings.h"
#include "memory.h"
#include "time.h"

void main()
{
    
    clear();
    print_string("Enter command>");
    char* prev_key = get_key_string();
    char waited = 0;
    while(1)
    {
        char* key = get_key_string();
        if(!compare_strings(key, "unknown"))
        {
            if(compare_strings(key, prev_key))
            {
                if(!waited)
                {
                    waited = 1;
                    sleep(3000000);
                }
                else
                {
                    waited = 0;
                    print_string(key);
                }
            }
            else
            {
                waited = 0;
                print_string(key);
            }
        }
        prev_key = key;
    }
    
}
