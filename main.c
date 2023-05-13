#include "shell.h"

/**
* main - entry point for the shell program
* Return: 0 on success, 1 on failure
*/
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	while (1)
	{
		print_prompt();
		nread = getline(&buffer, &bufsize, stdin);
		if (nread == -1) /* Ctrl-D or error */
		{
			if (feof(stdin)) /* Ctrl-D */
				putchar('\n');
			else /* error */
				perror("getline");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		buffer[nread - 1] = '\0'; /* remove newline */
		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else if (strcmp(buffer, "env") == 0)
		{
			check_env();
		}
		else
		{
			execute_command(buffer);
		}
	}

	return (0);
}

