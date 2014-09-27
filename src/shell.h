#ifndef SHELL_H
#define SHELL_H

#include "keyboard.h"
#include "screen.h"
#include "strings.h"
#include "commands.h"

#define MAX_COMMAND_SIZE 100

char exit_shell = 0;
char command[MAX_COMMAND_SIZE];
char command_cursor = 0;

void print_prompt()
{
    print_string("Enter command> ");
}

void process_key(KEY key)
{
    if(key >= 0 && key <=35)
    {
        char key_char = key_sym_to_char(key);
        print_char(key_char);
        command[command_cursor] = key_char;
        command_cursor++;
        command[command_cursor] = 0;
    }
    else if(key == KEY_BKSP && command_cursor > 0)
    {
        delete_char();
        command[command_cursor] = 0;
        command_cursor--;
        command[command_cursor] = ' ';
    }
}

void process_command()
{
   int argc;
   char **args = parse_command(command, &argc);

   unsigned int i;
   for(i=0; i<NUMBER_OF_COMMANDS; i++)
   {
       if(compare_strings(args[0], command_names[i])) 
       {
           command_functions[i](argc, args); 
           return;
       }
   }
   print_string("Command unknown");
}

void start_shell()
{
    clear();
    while(!exit_shell)
    {
        print_prompt();
    
        KEY next_key = get_next_key_pressed();
        while(next_key != KEY_ENTER)
        {
            process_key(next_key);
            next_key = get_next_key_pressed();
        }
        print_string("\n");
        process_command();
        print_string("\n");
        command_cursor = 0;
    }
    print_string("Exit command. Goodbye!");
}

#endif
