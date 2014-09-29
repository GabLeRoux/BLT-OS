#ifndef COMMANDS_H
#define COMMANDS_H

#include "strings.h"
#include "memory.h"
#include "list.h"

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

void add_token(list* tokens, char* command, int token_cursor_begin, int token_cursor_end)
{
    char* token = substring(command, token_cursor_begin, token_cursor_end);

    list_insert(tokens, (void*)token, 0); 
}

char isBlank(char c)
{
    char test = (c == ' ' || c == '\t' || c == '\n');
    return test; 
}

char** parse_command(char* command, int* argc)
{
    typedef enum{START, COMMAND, ARG, LITERAL, BLANK} State;
    int command_cursor = 0;
    int token_cursor_begin = 0;
    int token_cursor_end = 0;
    State state = START;
    list* tokens = list_create();
    
    while(command[command_cursor] != 0)
    {
        if(state == START)
        {
            if(!isBlank(command[command_cursor]))
            {
                state = COMMAND;
                token_cursor_begin = command_cursor;
            }
        }
        else if(state == COMMAND)
        {
            if(isBlank(command[command_cursor]))
            {
                state = BLANK;
                token_cursor_end = command_cursor - 1;
                add_token(tokens, command, token_cursor_begin, token_cursor_end);
            }
        }
        else if(state == BLANK)
        {
            if(isBlank(command[command_cursor]));
            else if(command[command_cursor] == '"')
            {
                state = LITERAL;
                token_cursor_begin = command_cursor + 1;
            }
            else
            {
                state = ARG;
                token_cursor_begin = command_cursor;
            }
        }
        else if(state == LITERAL)
        {
            if(command[command_cursor] == '"')
            {
                state = BLANK;
                token_cursor_end = command_cursor -1;
                add_token(tokens, command, token_cursor_begin, token_cursor_end);
            }
        }
        else if(state == ARG)
        {
            if(isBlank(command[command_cursor]))
            {
                state = BLANK;
                token_cursor_end = command_cursor - 1;
                add_token(tokens, command, token_cursor_begin, token_cursor_end);
            }
        }
        command_cursor++;
    }
    char** temp = (char**) malloc(tokens->count * sizeof(char*));
    int i;
    *argc = tokens->count;
    for(i=0; i<*argc; i++)
    {
        temp[i] = (char*)list_peek(tokens);
        list_pop(tokens);
    }
    return temp;
    
}

#endif
