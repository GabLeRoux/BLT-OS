#define VIDEO_MEMORY_ADDRESS 0Xb8000
char* cur_pos = (char*) VIDEO_MEMORY_ADDRESS;

void print(char* message)
{
    while(*message != 0)
    {
        if(*message == '\n')
        {
            cur_pos =  0xb8000 + ((((int)cur_pos - 0xb8000) / 160 + 1)*160);
        }
        else
        {
            *cur_pos = *message;
            cur_pos+=2;
        }
        
        message++;
    }
}

void clear()
{
    char* video_memory = (char*) VIDEO_MEMORY_ADDRESS;
    int i;
    for(i=0;i<4000;i++)
    {
        *video_memory = ' ';
        video_memory += 2;
    }
}

void main()
{
    
    clear();
    print("OK");
    
}
