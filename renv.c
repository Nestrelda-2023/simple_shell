#include "shell.h"


/**updated env.c file to remove extern **/
/**
 * check_env - checks and prints the environment variables
 * Return: environment variables
 */
void check_env(void)
{
	char **env = environ;

	while (*env)
	{
		char *equals = strchr(*env, '=');

		if (equals != NULL)
		{
			int index = (int)(equals - *env);
			char *name = malloc((index + 1) * sizeof(char));

			if (name == NULL)
			{
				print_malloc_error();
				exit(EXIT_FAILURE);
			}

			strncpy(name, *env, index);
			name[index] = '\0';
			printf("%s=%s\n", name, equals + 1);
			free(name);
		}

		env++;
	}
}
