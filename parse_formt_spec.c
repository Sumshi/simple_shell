#include "main.h"
/**
 * parse_format_specifier - returns the type of format specifier
 * @p: pointer to current character in fmt string
 *
 * Return: type of format specifier
 */
char parse_format_specifier(const char **p)
{
	char type = '\0';

	/* check for valid format specifier */
	if (**p == '%')
	{
		(*p)++;
		switch (**p)
		{
			case 'd':
			case 's':
			case 'c':
			case 'f':
				type = **p;
				break;
			default:
				/* Unsupported format specifier, just copy it to the output string*/
				type = **p;
				break;
		}
	}

	return (type);
}
