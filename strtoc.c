#include "shell.h"
/**
 * str_toc - Tokenize a string to tokens
 * @str: string to tokenize
 * @delim: delimiter char
 * @saveptr: Pointer to the saved position for subsequent calls
 * Return: Pointer to the next token in the string
 */
char *str_toc(char *str, const char *delim, char **saveptr)
{
	char *ax;
	char *te;

	if (str != NULL)
	{
		*saveptr = str;
	}
	else
	{
		if (*saveptr == NULL)
		{
			return (NULL);
		}
		str = *saveptr;
	}

	ax = str;
	te = str_pbrk(ax, delim);

	if (te != NULL)
	{
		*te = '\0';
		*saveptr = te + 1;
	}
	else
	{
		*saveptr = NULL;
	}

	return (ax);
}

