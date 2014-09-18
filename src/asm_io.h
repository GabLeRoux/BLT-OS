#ifndef ASM_IO_H
#define ASM_IO_H
unsigned char inb(unsigned short port)
{
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port) );
    return result;

}

void outb(unsigned char data, unsigned short port)
{
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

#endif
