#include "shell.h"
#include "list.h"

char compare(void* a, void* b)
{
    return *((char*)a) == *((char*)b);
}

void main()
{
    clear();
    list* l = list_create();
    char n = 'n';
    list_push(l,(void*) &n);
    char u = 'u';
    list_node* ln =  list_push(l,(void*) &u);
    char t = 't';
    list_push(l,(void*) &t);
    char r = 'r';
    list_push(l,(void*) &r);
    char o = 'o';
    list_push(l,(void*) &o);

    list_delete(l, 4);
    list_delete(l, 0);
    list_delete(l, 1);


    char k = 'v';
    list_insert(l, (void*) &k, 1);

    print_string("Size:\n");
    print_int(list_size(l));
    print_string("\n");
   
    print_string("Values:\n");
    int i;
    for(i=0; i<list_size(l); i++)
    {
        char* c = (char*) list_get(l,i);
        print_char(*c);
        print_string("\n");
    }

    char a = 'i';
    print_int(list_find(l, &a, compare));

    

/*
    char* a = (char*)list_get(l, 0);
    print_char(*a);
    a = (char*)list_get(l, 1);
    print_char(*a);
    a = (char*)list_get(l, 2);
    print_char(*a);
*/

    list_free(l);
    //start_shell();    
}
