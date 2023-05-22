#include "main.h"
/**
 * my_vsnprintf - vsnprintf implementation
 * @buf: The buffer to write to
 * @size: The size of the buffer
 * @format: The format string
 * @arg: The variadic argument list
 * Return: The number of characters written
 */
int my_vsnprintf(char *buf, size_t size, const char *format, va_list arg)
{
	int written = 0;
	size_t remaining = size > 0 ? size - 1 : 0;

	while (*format != '\0' && remaining > 0)
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' */
			if (*format == '\0')
				break; /* Unexpected end of format string */
			if (*format == '%')
			{
				write_character(&buf, '%', &remaining, &written);
				format++;
				continue;
			}
			if (*format == 's')
			{
				char *arg_str = va_arg(arg, char *);

				write_str(&buf, arg_str, &remaining, &written);
				format++;
				continue;
			}
			if (*format == 'd')
			{
				int arg_int = va_arg(arg, int);

				write_int(&buf, arg_int, &remaining, &written);
				format++;
				continue;
			}
		}

		write_character(&buf, *format++, &remaining, &written);
	}
	if (size > 0)
		*buf = '\0';
	return (written);
}
