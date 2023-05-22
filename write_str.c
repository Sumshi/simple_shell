#include "main.h"
/**
 * write_string - Write string to string
 * @str: Pointr to output string
 * @s: string to write
 *
 * Return: Number of characters written
 */
int write_string(char **str, const char *s)
{
	int count = 0;
	int i;

	for (i = 0; s[i]; i++)
	{
		*(*str)++ = s[i];
		count++;
	}

	return (count);
}
