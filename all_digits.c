#include "main.h"

/**
 * _isdigit - checks for digits.
 * @str: the int to check if it's a digit.
 *
 * Return: 1 is a digit and 0 otherwise
 */
int _isdigit(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
