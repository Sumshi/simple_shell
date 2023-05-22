#include "main.h"
/**
 * write_char - writes character to string
 * @str: pointer to output string
 * @c: character to write
 *
 * Return: Number of characters written
 */
int write_char(char **str, char c)
{
	*(*str)++ = c;

	return (1);
}
