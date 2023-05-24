#include "shell.h"

/**
 * exec_ute - execute a command
 * @cmd: command to execute
 */
void exec_ute(char *cmd)
{
	char *commands[MAX_COMMAND_LENGTH];
	int cmd_count = 0;
	int i = 0;

	par_se(cmd, commands, &cmd_count);

	while (i < cmd_count)
	{
		char *command = commands[i];
		char *args[MAX_COMMAND_LENGTH];
		int arg_count = 0;

		par_se(command, args, &arg_count);

		if (strcmp(args[0], "exit") == 0)
		{
			ex_it(args, arg_count);
		}
		else if (strcmp(args[0], "cd") == 0)
		{
			cd(args, arg_count);
		}
		else if (strcmp(args[0], "setenv") == 0)
		{
			set_env_var(args, arg_count);
		}
		else if (strcmp(args[0], "unsetenv") == 0)
		{
			unset_env_var(args, arg_count);
		}
		else
		{
			exe_com(args, program_name);
		}

		i++;
	}
}

/**
 * exe_com - execute a command
 * @args: command arguments
 * @program_name: name of the program
 */
void exe_com(char *args[], char *program_name)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		/*fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);*/
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "%s: %s: command not found\n", program_name, args[0]);
		}
	}
}

/**
 * ex_it - handle the 'exit' command
 * @args: array of command arguments
 * @arg_count: number of arguments
 */
void ex_it(char *args[], int arg_count)
{
	if (arg_count == 1)
	{
		exit(EXIT_SUCCESS);
	}
	else if (arg_count == 2)
	{
		int status = atoi(args[1]);

		exit(status);
	}
	else
	{
		fprintf(stderr, "Usage: exit [status]\n");
		return;
	}
}

