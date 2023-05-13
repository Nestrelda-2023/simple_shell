#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stddef.h>


#define PROMPT "$"

extern char **environ;
void print_prompt(void);
void check_env(void);
void execute_command(char *command_line);

void print_error(char *msg);
void prompt(char *msg);
void print_command_not_found_error(void);
void print_malloc_error(void);
void print_execvp_error(void);


#endif

