#ifndef LIST_H
#define LIST_H

#include "screen.h"
#include "memory.h"

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

list_node* list_push(list* l, void* data)
{
    list_node* ln = malloc(sizeof(list_node));
    if(l->count == 0)
    {
        l->first = ln;
        ln->next = 0;
        ln->prev = 0;
    }
    else
    {
        ln->next = l->last->next;
        ln->prev = l->last;
        l->last->next = ln;
    }
    ln->data = data;
    l->last= ln;
    
    l->count++;
    return ln;
}

void list_pop(list* l)
{
    if(l->last == 0)
    {
        print_string("Error: Popping empty list");
        return;
    }
    list_node* new_last = l->last->prev;
    list_node* last = l->last;
    void* data = last->data;
    if(new_last != 0)
    {
        new_last->next = 0;
    }
    l->last = new_last;
    l->count--;
    free(last);
    
}

void* list_get(list* l, int pos)
{
    if(pos >= l->count)
    {
        print_string("Error: invalid list get position");
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

unsigned int list_size(list* l)
{
    return l->count;
}

void list_insert(list* l, void* new_data, int pos)
{
    if(pos > l->count) 
    {
        print_string("Error: invalid list insert position");
        return;
    }
    if(pos == l->count)
    {
        list_push(l, new_data);
        return;
    }
    list_node* ln = l->first;
    int i;
    for(i=0; i<pos; i++)
    {
        ln = ln->next;
    }
    list_node* new_node = malloc(sizeof(list_node));
    new_node->prev = ln->prev;
    new_node->next = ln;
    new_node->data = new_data;
    if(pos == 0)
    {
        l->first = new_node;
    }
    else
    {
        ln->prev->next = new_node;
    }
    ln->prev = new_node;
    l->count++;
}

void list_delete(list* l, int pos)
{
    if(pos >= l->count)
    {
        print_string("Error: invalid list delete position");
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

int list_find(list* l, void* value, char (*cmp)(void*,void*))
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
