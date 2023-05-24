#include "shell.h"

/**
 * str_pbrk - Searches a string for any set of bytes
 * @str: string to be searched
 * @delim: bytes to be searched
 *
 * Return: Pointer to the byte in str that matches one of the bytes in delim
 *         else NULL
 */
char *str_pbrk(const char *str, const char *delim)
{
	const char *s1 = str;
	const char *s2;

	while (*s1 != '\0')
	{
		s2 = delim;
		while (*s2 != '\0')
		{
			if (*s1 == *s2)
				return ((char *)s1);
			s2++;
		}
		s1++;
	}

	return (NULL);
}

