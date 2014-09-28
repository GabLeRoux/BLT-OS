#ifndef COMMANDS_H
#define COMMANDS_H

#include "strings.h"
#include "memory.h"

#define NUMBER_OF_COMMANDS 2


extern char exit_shell;

int exit_command(int argc, char** argv)
{
    exit_shell = 1;
}

int echo_command(int argc, char** argv)
{
    int i;
    for(i=1; i<argc; i++)
    {
        print_string(argv[i]);
        print_string("\n");
    }
}

char *command_names[NUMBER_OF_COMMANDS] = {
    "exit",
    "echo"
};

int (*command_functions[NUMBER_OF_COMMANDS])(int,char**) = {
    exit_command,
    echo_command
};

char** parse_command(char* command, int* argc)
{
    typedef enum{START, COMMAND, ARGS, LITERAL} state;
    int current_cursor = 0;
    char** temp = (char**)malloc(length_string(command));
    return temp;
    /*
    while(command[current_cursor] != 0)
    {
        
    }
    */
}

#endif
