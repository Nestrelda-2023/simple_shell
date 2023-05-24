#include "shell.h"
#include "gvar.h"

/**
 * main - Entry point for the shell
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	(void)argc;
	program_name = argv[0];

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

		exec_ute(buffer);
		free(buffer);
	}

	return (0);
}

