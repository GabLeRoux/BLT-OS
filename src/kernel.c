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
       char* cur = VIDEO_MEMORY_ADDRESS + i; 
       char* next = VIDEO_MEMORY_ADDRESS + i + (VIDEO_COLUMNS * BYTES_PER_CHAR); 
       *cur = *next;
    } 
}

void print_char(char c)
{
    if(c == '\n')
    {
        cur_pos =  VIDEO_MEMORY_ADDRESS + ((((int)cur_pos - VIDEO_MEMORY_ADDRESS) / (VIDEO_COLUMNS * BYTES_PER_CHAR) + 1)*(VIDEO_COLUMNS * BYTES_PER_CHAR));
        if(cur_pos >= VIDEO_ADDRESS_END)
        {
            screen_up();
            cur_pos -= VIDEO_COLUMNS * BYTES_PER_CHAR;
        }
    }
    else
    {
        *cur_pos = c;
        cur_pos += BYTES_PER_CHAR;
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

void print_int(int n)
{ 
    int i;
    for(i=count_digits(n)-1;i>=0;i--)
    {
       int p = pow(10,i);
       print_char(n/p + '0');
       n %= p;
    }
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

void main()
{
    
    clear();
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OK\n");
    print_string("OKK\n");
    print_string("OKKK\n");
    print_int(99499);
    print_char('\n');
    print_int(67111);
    
}
