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
		char *equals = _strchr(*env, '=');

		if (equals != NULL)
		{
			int index = (int)(equals - *env);
			char *name = malloc((index + 1) * sizeof(char));

			if (name == NULL)
			{
				print_malloc_error();
				exit(EXIT_FAILURE);
			}

			_strncpy(name, *env, index);
			name[index] = '\0';
			printf("%s=%s\n", name, equals + 1);
			free(name);
		}

		env++;
	}
}
/**
 * _strchr - Locate character in string.
 * @s: The string to search.
 * @c: The character to locate.
 *
 * Return: Pointer to the first occurrence of character c in string s,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	return (strchr(s, c));
}

/**
 * _strncpy - Copy a string.
 * @dest: The destination buffer.
 * @src: The source string.
 * @n: The maximum number of characters to copy.
 *
 * Return: Pointer to the destination buffer.
 */
char *_strncpy(char *dest, char *src, int n)
{
	return (strncpy(dest, src, n));
}

