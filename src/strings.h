#ifndef STRINGS_H
#define STRINGS_H

#include "memory.h"

char compare_strings(char* s1, char* s2)
{
    while(*s1 != '\0')
    {
        if(*s1 != *s2) return 0;
        s1++;
        s2++;
    }
    if(*s2 == '\0') return 1;
    else return 0;
}

int length_string(char* str)
{
    int c = 0;
    while(*str != '\0')
    {
        str++;
        c++;
    }
    return c;
}

void copy_string(char* str, char* out)
{
    while(*str != '\0')
    {
        *out = *str;
        out++;
        str++;
    }
    *out = '\0';
}

void concatenate_strings(char* s1, char* s2, char* out)
{
    while(*s1 != '\0')
    {
        *out = *s1;
        out++;
        s1++;
    }
    while(*s2 != '\0')
    {
        *out = *s2;
        out++;
        s2++;
    }
    *out = '\0';
    
}

char* substring(char* string, int start, int end)
{
    char* result = (char*) malloc(end - start + 2);
    char* temp = result;
    int i;
    for(i=start; i<=end; i++)
    {
        *result = string[i];
        result++;
    }
    *result = 0;
    return temp;
}
#endif
