#include "shell.h"
#include "gvar.h"

/**
 * main - Entry point of the shell program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	char *buffer;
	(void)argc;
	program_name = argv[0];

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			print_prompt();
			buffer = get_line();
			if (buffer == NULL)
			{
				putchar('\n');
				continue;
			}

			exec_ute(buffer);
			free(buffer);
		}
	}
	else
	{
		char *line = NULL;
		size_t line_size = 0;
		ssize_t chars_read;

		while ((chars_read = getline(&line, &line_size, stdin)) != -1)
		{
			if (chars_read > 0 && line[chars_read - 1] == '\n')
				line[chars_read - 1] = '\0';

			if (line[0] == '\0')
			{
				putchar('\n');
				continue;
			}

			exec_ute(line);
		}

		free(line);
	}

	return (0);
}

