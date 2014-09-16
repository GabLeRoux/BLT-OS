void main()
{
    char* video_memory = (char*) 0xb8000;
    char* message = "Fuck yeah!";
    
    int i;
    for(i=0;i<800;i++)
    {
        *video_memory = ' ';
        video_memory += 2;
    }
    
    video_memory = (char*) 0xb8000;
    while(*message != 0)
    {
        *video_memory = *message;
        video_memory+=2;
        message++;
    }

}
