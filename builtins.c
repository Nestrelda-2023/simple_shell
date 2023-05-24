#include "shell.h"

/**
 * set_env_var - Set an environment variable.
 * @args: Array of command arguments.
 * @arg_count: Number of arguments.
 */
void set_env_var(char *args[], int arg_count)
{
	if (arg_count < 3)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}

	if (setenv(args[1], args[2], 1) != 0)
	{
		fprintf(stderr, "Failed to set environment variable\n");
	}
}

/**
 * unset_env_var - Unset an environment variable.
 * @args: Array of command arguments.
 * @arg_count: Number of arguments.
 */
void unset_env_var(char *args[], int arg_count)
{
	if (arg_count < 2)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return;
	}

	if (unsetenv(args[1]) != 0)
	{
		fprintf(stderr, "Failed to unset environment variable\n");
	}
}

/**
 * cd - Change the current directory.
 * @args: Array of command arguments.
 * @arg_count: Number of arguments.
 */
void cd(char *args[], int arg_count)
{
	char *path = args[1];
	char *current_directory;

	if (arg_count == 1 || (arg_count == 2 && _strcmp(path, "~") == 0))
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			fprintf(stderr, "cd: No home directory found\n");
			return;
		}
	}
	else if (_strcmp(path, "-") == 0)
	{
		path = getenv("OLDPWD");
		if (path == NULL)
		{
			fprintf(stderr, "cd: No previous directory found\n");
			return;
		}
	}

	current_directory = getcwd(NULL, 0);
	if (current_directory == NULL)
	{
		fprintf(stderr, "cd: Failed to get current directory: %s\n", strerror(errno));
		return;
	}

	if (chdir(path) != 0)
	{
		fprintf(stderr, "cd: Failed to change directory to '%s': %s\n", path, strerror(errno));
	}
	else
	{
		setenv("OLDPWD", current_directory, 1);
		setenv("PWD", getcwd(NULL, 0), 1);
	}

	free(current_directory);
}

