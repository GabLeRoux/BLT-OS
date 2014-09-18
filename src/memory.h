#ifndef MEMORY_H
#define MEMORY_H

#include "strings.h"
#include "error.h"

#define HEAP_BEGINNING 0X100000
#define HEAP_END 0xffffffff

typedef enum {FREE, USED} status;

typedef struct
{
    void* next;
    status status;
} mem_head;

void* heap_ptr = (void*) HEAP_BEGINNING; 

void* find_space(int number_of_bytes)
{
    mem_head* current_header = (mem_head*) HEAP_BEGINNING;
    while(current_header->status != FREE || (int)current_header->next - ((int)current_header + sizeof(mem_head)) < number_of_bytes)
    {
        if((void*) current_header->next == heap_ptr)
        {
            char* err_str = "not enough memory in malloc\n"; 
            print_string(err_str);
            error_string = err_str;
            return 0;
        }
        current_header = (mem_head*) current_header->next;
    }
    mem_head header;
    header.next = (void*) current_header + sizeof(mem_head) + number_of_bytes;
    header.status = USED;
    void* temp_next = current_header->next;
    *current_header = header; 
    void* new_ptr = (void*) current_header + sizeof(mem_head);
    if(temp_next - header.next < 20)
    {
        header.next = temp_next;
    }
    else
    {
        mem_head middle_header;
        middle_header.next = temp_next;
        header.status = FREE;
        *((mem_head*)header.next) = middle_header;
    }
    return new_ptr;
}

void* malloc(int number_of_bytes)
{
    if(heap_ptr + sizeof(mem_head) + number_of_bytes > (void*)HEAP_END)
        return find_space(number_of_bytes); 
    else
    {
       mem_head header;
       header.next = heap_ptr + sizeof(mem_head) + number_of_bytes;
       header.status = USED;
       *((mem_head*) heap_ptr) = header; 
       void* new_ptr = heap_ptr + sizeof(mem_head);
       heap_ptr = header.next;
       return new_ptr; 
    }
}

void free(void* freed_address)
{
    mem_head* current_header = (mem_head*) HEAP_BEGINNING;
    while(current_header->next < freed_address)
    {
        current_header = (mem_head*) current_header->next;
    }
    current_header->status = FREE;
}

#endif
