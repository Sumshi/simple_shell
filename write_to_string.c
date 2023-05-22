#include "main.h"
/**
 * write_to_str - write formatted value to string
 * @str: Pointer to output string
 * @type: format specifier type
 * @arg: Variadic argument list
 *
 * Return: Number of characters written
 */
int write_to_str(char **str, char type, va_list arg)
{
	int count = 0;

	switch (type)
	{
		case 'd':
			{
				int num = va_arg(arg, int);

				count += write_integer(str, num);
				break;
			}
		case 's':
			{
				const char *s = va_arg(arg, const char *);

				count += write_string(str, s);
				break;
			}
		case 'c':
			{
				char c = (char)va_arg(arg, int);

				count += write_char(str, c);
				break;
			}
		case 'f':
			{
				float num = va_arg(arg, double);

				count += write_float(str, num);
				break;
			}
	}

	return (count);
}
