#include "shell.h"
/**
 * str_toc - Tokenize a string into consecutive tokens
 * @str: The string to tokenize
 * @delim: The delimiter character(s)
 * @saveptr: Pointer to the saved position for subsequent calls
 *
 * Return: Pointer to the next token in the string
 */
char *str_toc(char *str, const char *delim, char **saveptr)
{
	char *token_start;
	char *token_end;

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

	token_start = str;
	token_end = str_pbrk(token_start, delim);

	if (token_end != NULL)
	{
		*token_end = '\0';
		*saveptr = token_end + 1;
	}
	else
	{
		*saveptr = NULL;
	}

	return (token_start);
}

