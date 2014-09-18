#ifndef MATH_H
#define MATH_H
int count_digits(int n)
{
    int c = 1;
    while(n >= 10 || n <= -10)
    {
        n /= 10;
        c++;
    }
    return c;
}

int pow(int n, int p)
{
    int result = 1;
    int i;
    for(i=0;i<p;i++)
    {
        result *= n; 
    }
    return result;
}
#endif
