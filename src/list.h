#ifndef LIST_H
#define LIST_H

#include "screen.h"
#include "memory.h"
#include "error.h"

typedef struct list_node
{
    struct list_node* prev;
    struct list_node* next;
    void* data;
} list_node;


typedef struct
{
  list_node* first;
  list_node* last;
  int count;
} list;

list* list_create()
{
    list* l = malloc(sizeof(list));
    l->first = 0;
    l->last = 0;
    l->count = 0;
    return l;
}

unsigned int list_size(list* l)
{
    return l->count;
}

void* list_get(list* l, int pos)
{
    if(pos >= l->count)
    {
        error_string = "Error: invalid list get position";
        print_string(error_string);
        return;
    }
    list_node* ln = l->first;
    int i;
    for(i=0; i<pos; i++)
    {
        ln = ln->next;
    }
    return ln->data;
    
}

void list_insert(list* l, void* new_data, int pos)
{
    if(pos > l->count) 
    {
        error_string = "Error: invalid list insert position";
        print_string(error_string);
        return;
    }
    
    list_node* new_node = malloc(sizeof(list_node));
    new_node->data = new_data;
    if(l->count == 0)
    {
        l->last = new_node;
        l->first = new_node;
        new_node->prev = new_node->next = 0;
    }
    else if(pos == 0)
    {
        new_node->next = l->first;
        new_node->prev = 0;
        l->first->prev = new_node;
        l->first = new_node;
    }
    else if(pos == l->count)
    {
        new_node->prev = l->last; 
        new_node->next = 0;
        l->last->next = new_node;
        l->last = new_node;
    }
    else
    {
        list_node* ln = l->first;
        int i;
        for(i=0; i<pos; i++)
        {
            ln = ln->next;
        }
        new_node->next = ln;
        new_node->prev = ln->prev;
        ln->prev->next = new_node;
        ln->prev = new_node;
    }
    l->count++;
}

void list_delete(list* l, int pos)
{
    if(pos >= l->count)
    {
        error_string = "Error: invalid list delete position";
        print_string(error_string);
        return;
    }
    list_node* ln = l->first;
    int i;
    for(i=0; i<pos; i++)
    {
        ln = ln->next;
    }
    if(l->count == 1)
    {
        l->first = l->last = 0;
    }
    else if(ln == l->first)
    {
        ln->next->prev = 0;
        l->first = ln->next;
    }
    else if(ln == l->last)
    {
        ln->prev->next = 0;
        l->last = ln->next;
    }
    else
    {
        ln->prev->next = ln->next;
        ln->next->prev = ln->prev;
    }
    free(ln);
    l->count--;
}

int list_find_with_func(list* l, void* value, char (*cmp)(void*,void*))
{
    list_node* ln = l->first;
    int i;
    for(i=0; i<(l->count); i++)
    {
        if(cmp(value, ln->data)) return i;
        ln = ln->next;
    }
    return -1;
}

char compare_bytes(void* value, void* data, int bytes)
{
    char equal = 1;
    char* c_val = (char*) value;
    char* c_dat = (char*) data;
    int i;
    for(i=0; i<bytes; i++, c_val++, c_dat++)
    {
	if(*c_val != *c_dat)
        {
            return 0;
        }        
    }
    return equal;
}

int list_find(list* l, void* value, int bytes)
{
    list_node* ln = l->first;
    int i;
    for(i=0; i<(l->count); i++)
    {
        if(compare_bytes(value, ln->data, bytes)) return i;
        ln = ln->next;
    }
    return -1;
}

void* list_peek(list* l)
{
    return list_get(l, l->count - 1);
}

void list_push(list* l, void* data)
{
    list_insert(l, data, l->count);
}

void list_pop(list* l)
{
     list_delete(l, l->count - 1);  
}

void list_free(list* l)
{
    list_node* cur_ln = l->first;
    while(cur_ln !=0)
    {
        list_node* next_ln = cur_ln->next;
        free(cur_ln);
        cur_ln = next_ln;
    }
    free(l); 
}


#endif
