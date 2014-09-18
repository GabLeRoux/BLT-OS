#ifndef MEMORY_H
#define MEMORY_H

#define MAX_HEAP 10000
char heap[MAX_HEAP];
char* heap_ptr = heap;

char* malloc(int number_of_bytes)
{
    char* temp = heap_ptr;
    if(heap_ptr + number_of_bytes > heap + MAX_HEAP)
        return 0;
    heap_ptr += number_of_bytes;
    return temp;
     

}
#endif
