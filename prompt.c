#include "shell.h"

/**
* print_error - Prints an error message to stderr
* @msg: The error message to print
*/
void print_error(char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
}

/**
* prompt - Prints a prompt message to stdout
* @msg: The prompt message to print
*/
void prompt(char *msg)
{
	printf("%s", msg);
	fflush(stdout);
}

/**
* print_command_not_found_error - Prints an error message
*/
void print_command_not_found_error(void)
{
	print_error("Command not found");

}

/**
* print_malloc_error - Prints an error indicating a mialloc failure
*/
void print_malloc_error(void)
{
	print_error("Memory allocation failed");
}

/**
* print_execvp_error - Prints an error message
*/
void print_execvp_error(void)
{
	print_error("Execution failed");

}

