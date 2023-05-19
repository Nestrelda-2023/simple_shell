#include "shell.h"
#include "gvar.h"
/*char *program_name; 
char *buffer = NULL; 
size_t bufsize = 0;
ssize_t nread;*/

/**
 * main - entry point for the shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
    (void)argc; /* Suppress unused parameter warning */
    program_name = argv[0]; /* Assign program name from argv[0] */

    while (1)
    {
        print_prompt();
        buffer = get_line();
        if (buffer == NULL)
        {
            putchar('\n');
            free(buffer);
            exit(EXIT_SUCCESS);
        }
        /* Execute command */
        exec_ute(buffer);
        free(buffer);
    }

    return 0;
}

