#ifndef SHELL_H
#define SHELL_H


#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stddef.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define PROMPT "$"
#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

extern char *program_name;
extern char **environ;
void print_prompt(void);
void check_env(void);
void exec_ute(char *cmd);

void print_error(char *msg);
void prompt(char *msg);
void print_command_not_found_error(void);
void print_malloc_error(void);
void print_execvp_error(void);

char *get_line();

void par_se(char *cmd, char *args[], int *arg_count);
void ex_it(char *args[], int arg_count);
void exe_com(char *args[], char *program_name);
void set_env_var(char *args[], int arg_count);
void unset_env_var(char *args[], int arg_count);
void cd(char *args[], int arg_count);

char* str_pbrk(const char* str, const char* delim);
char* str_toc(char* str, const char* delim, char** saveptr);
char *_strchr(char *s, char c);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);

#endif

