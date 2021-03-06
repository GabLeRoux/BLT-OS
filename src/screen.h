#ifndef SCREEN_H
#define SCREEN_H

#include "math.h"

#define VIDEO_MEMORY_ADDRESS 0Xb8000
#define VIDEO_COLUMNS 80
#define VIDEO_ROWS 25
#define BYTES_PER_CHAR 2 
#define VIDEO_ADDRESS_END (VIDEO_MEMORY_ADDRESS + (VIDEO_COLUMNS * VIDEO_ROWS * BYTES_PER_CHAR))

char* cur_pos = (char*) VIDEO_MEMORY_ADDRESS;

void screen_up()
{
    int i;
    for(i=0; i < (VIDEO_ROWS -1) * VIDEO_COLUMNS * BYTES_PER_CHAR; i++)
    {
       char* cur = (char*) VIDEO_MEMORY_ADDRESS + i; 
       char* next = (char*) VIDEO_MEMORY_ADDRESS + i + (VIDEO_COLUMNS * BYTES_PER_CHAR); 
       *cur = *next;
    } 
}

void print_char(char c)
{
    if(c == '\n')
    {
        cur_pos =  (char*) VIDEO_MEMORY_ADDRESS + ((((int)cur_pos - VIDEO_MEMORY_ADDRESS) / (VIDEO_COLUMNS * BYTES_PER_CHAR) + 1)*(VIDEO_COLUMNS * BYTES_PER_CHAR));

    }
    else
    {
        *cur_pos = c;
        cur_pos += BYTES_PER_CHAR;
    }
    if(cur_pos >= (char*) VIDEO_ADDRESS_END)
    {
        screen_up();
        cur_pos -= VIDEO_COLUMNS * BYTES_PER_CHAR;
    }
}

void print_string(char* message)
{
    while(*message != 0)
    {
        print_char(*message); 
        
        message++;
    }
}

void print_unsigned_int(unsigned int n)
{ 
    int i;
    for(i=count_digits(n)-1;i>=0;i--)
    {
       int p = pow(10,i);
       print_char(n/p + '0');
       n %= p;
    }
}

void print_int(int n)
{ 
    if(n < 0)
    {
        print_char('-');
        print_unsigned_int(-n);
    }
    else print_unsigned_int(n);
}

void clear()
{
    char* video_memory = (char*) VIDEO_MEMORY_ADDRESS;
    int i;
    for(i=0;i<VIDEO_COLUMNS * VIDEO_ROWS;i++)
    {
        *video_memory = ' ';
        video_memory += BYTES_PER_CHAR;
    }
}

void delete_char()
{
    cur_pos -= BYTES_PER_CHAR; 
    *cur_pos = ' ';
}

#endif
