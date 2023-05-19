#include "shell.h"

/**
 * exec_ute - execute a command
 * @cmd: command to execute
 */
void exec_ute(char *cmd)
{
    char *args[MAX_COMMAND_LENGTH];
    int arg_count = 0;

    if (cmd[0] == '\0')
        return;

    par_se(cmd, args, &arg_count);

    if (strcmp(args[0], "exit") == 0)
    {
        ex_it(args, arg_count);
        return;
    }

    exe_com(args, program_name);
}

/**
 * par_se - parse a command line
 * @cmd: command line to parse
 * @args: array to store the parsed arguments
 * @arg_count: pointer to the argument count variable
 */
void par_se(char *cmd, char *args[], int *arg_count)
{
    int i = 0;

    while (cmd[i] != '\0' && *arg_count < MAX_COMMAND_LENGTH - 1)
    {
        while (cmd[i] == ' ' || cmd[i] == '\t')
            i++;

        if (cmd[i] != '\0')
        {
            args[*arg_count] = &cmd[i];
            (*arg_count)++;

            while (cmd[i] != ' ' && cmd[i] != '\t' && cmd[i] != '\0')
                i++;

            if (cmd[i] != '\0')
            {
                cmd[i] = '\0';
                i++;
            }
        }
    }

    args[*arg_count] = NULL;
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

/**
 * exe_com - execute a command
 * @args: array of command arguments
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
        fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
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

