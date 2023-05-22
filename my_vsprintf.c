#include "main.h"
/**
 * _vsprintf - implementation of the vsprintf func
 * @str: character string
 * @fmt: writes to character string
 * @arg: variadic argument
 *
 * Return: on success, number of characters printed.
 */
int _vsprintf(char *str, const char *fmt, va_list arg)
{
	int count = 0;
	const char *p = fmt;
	char type;

	while (*p)
	{
		if (*p == '%')
		{
			p++;

			type = parse_format_specifier(&p);

			count += write_to_str(&str, type, arg);
		}
		else
		{
			*str++ = *p;
			count++;
		}

		p++;
	}

	*str = '\0';  /* Null-terminate the output string*/

	return (count);
}
