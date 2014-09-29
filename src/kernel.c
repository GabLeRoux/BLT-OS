#include "shell.h"
#include "list.h"

char compare(void* a, void* b)
{
    return *((char*)a) == *((char*)b);
}

void main()
{
    start_shell();    
}
