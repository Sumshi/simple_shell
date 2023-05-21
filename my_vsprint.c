#include "main.h"
/**
 * s_itoa - converts int to a string
 * @num: integer to be converted
 * @str: string converted.
 * Return: on success, the str is returned.
 */
char *s_itoa(int num, char *str)
{
	int i = 0;
	int is_negative = 0;
	int j;

	/* Handle negative numbers*/
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	/* Convert the number to string in reverse order*/
	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num);

	/* Add the negative sign if necessary*/
	if (is_negative)
		str[i++] = '-';

	/* Reverse the string*/
	for (j = 0; j < i / 2; j++)
	{
		char temp = str[j];

		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}

	/* Null-terminate the string*/
	str[i] = '\0';

	return (str);
}
/**
 * _vsprintf - implementation of the vsprintf func
 * @str: character string
 * @fmt: writes to character string
 * @arg: variadic argument
 * Return: on success, number of characters printed.
 */
int _vsprintf(char *str, const char *fmt, va_list arg)
{
	int count = 0;
	const char *p = fmt;
	int i, decimal_digits, digit;

	while (*p)
	{
		if (*p == '%')
		{
			p++;
			if (*p == 'd')
			{
				int num = va_arg(arg, int);
				char num_str[12];  /* Adjust the size as needed*/
				s_itoa(num, num_str);
				i = 0;

				while (num_str[i])
				{
					*str++ = num_str[i++];
					count++;
				}
			}
			else if (*p == 's')
			{
				char *str_arg = va_arg(arg, char*);
				int i = 0;

				while (str_arg[i])
				{
					*str++ = str_arg[i++];
					count++;
				}
			}
			else if (*p == 'c')
			{
				char c = (char)va_arg(arg, int);
				*str++ = c;
				count++;
			}
			else if (*p == 'f')
			{
				double num = va_arg(arg, double);
				int int_part = (int)num;
				double decimal_part = num - int_part;

				char int_str[12];  /* Adjust the size as needed*/
				s_itoa(int_part, int_str);
				i = 0;

				while (int_str[i])
				{
					*str++ = int_str[i++];
					count++;
				}

				*str++ = '.';
				count++;

				decimal_digits = 6;  /*Number of decimal places to display*/
				while (decimal_digits > 0)
				{
					decimal_part *= 10;
					digit = (int)decimal_part;
					*str++ = digit + '0';
					count++;
					decimal_part -= digit;
					decimal_digits--;
				}
			}
			else
			{
				/* Unsupported format specifier, just copy it to the output string*/
				*str++ = *p;
				count++;
			}
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
