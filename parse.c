#include "shell.h"

/**
 * par_se - Parse and separate the command into arguments
 * @cmd: The command to parse
 * @args: Array to store the arguments
 * @arg_count: Pointer to the count of arguments
 */
void par_se(char *cmd, char *args[], int *arg_count)
{
	char *saveptr;
	char *token;

	/* If cmd is empty, set arg_count to 0 and return */
	if (cmd[0] == '\0')
	{
		*arg_count = 0;
		args[*arg_count] = NULL;
		return;
	}

	token = str_toc(cmd, DELIM, &saveptr);
	while (token != NULL && *arg_count < MAX_COMMAND_LENGTH - 1)
	{
		args[*arg_count] = token;
		(*arg_count)++;
		token = str_toc(NULL, DELIM, &saveptr);
	}

	args[*arg_count] = NULL;
}

