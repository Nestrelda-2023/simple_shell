#include "shell.h"
#include "gvar.h"


/**
 * main - entry point for the shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
    (void)argc; /* Suppress argc*/
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

