#include "shell.h"

/**
* execute_command - executes a command line input
* @command_line: pointer to command line
* Return: null
*/
void execute_command(char *command_line)
{
	char *token;
	char *args[100];
	int i = 0;
	pid_t pid;

	token = strtok(command_line, " ");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	pid = fork();
	if (pid == -1)
	{
		print_error("Fork Failed");
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		print_execvp_error();
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			print_command_not_found_error();
		}
	}
}

