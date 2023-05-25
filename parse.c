#include "shell.h"

/**
* par_se - Parse and separate the command into arguments
* @cmd: The command to parse
* @args: Array to store the arguments
* @arg_count: Pointer to the count of arguments
*/
void par_se(char *cmd, char *args[], int *arg_count)
{
	int i = 0;
	int in_arg = 0;
	int arg_start = 0;
	*arg_count = 0;

	while (cmd[i] != '\0')
	{
		if (cmd[i] == ' ')
		{
			if (in_arg)
			{
				args[*arg_count] = &cmd[arg_start];
				cmd[i] = '\0';
				(*arg_count)++;
				in_arg = 0;
			}
		}
		else
		{
			if (!in_arg)
			{
				arg_start = i;
				in_arg = 1;
			}
		}
		i++;
		}

	if (in_arg)
	{
		args[*arg_count] = &cmd[arg_start];
		(*arg_count)++;
	}

	args[*arg_count] = NULL;
}


/**
* _strcmp - Compare two strings.
* @s1: The first string.
* @s2: The second string.
*
* Return: Negative value if s1 is less than s2,
*         0 if s1 and s2 are equal,
*         Positive value if s1 is greater than s2.
*/
int _strcmp(char *s1, char *s2)
{
	return (strcmp(s1, s2));
}
