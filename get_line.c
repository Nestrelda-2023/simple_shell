#include "shell.h"

/**
 * get_line - Read a line of input from the user.
 * Return: The line of input entered by the user.
 */
char *get_line()
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_pos;
	static ssize_t chars_read;
	char *line = NULL;
	size_t line_len = 0;
	char current_char;

	while (1)
	{
		if (buffer_pos >= (size_t)chars_read)
		{
			chars_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (chars_read == 0)
			{
				if (line_len == 0)
				{
					putchar('\n');
					return (NULL);
				}
				break;
			}
			else if (chars_read < 0)
			{
				perror("read");
				exit(EXIT_FAILURE);
			}
		}

		current_char = buffer[buffer_pos++];

		if (current_char == '\n')
			break;

		line = realloc(line, line_len + 1);
		if (line == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}

		line[line_len++] = current_char;
	}

	if (line != NULL)
	{
		line = realloc(line, line_len + 1);
		if (line == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		line[line_len] = '\0';
	}

	return (line);
}

