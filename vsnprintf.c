#include "main.h"
/**
 * my_vsnprintf - vsnprintf implementation
 * @buf: string
 * @size: size of string
 * @format: character string
 * @arg: variadic list
 * Return: number of characters
 */
int my_vsnprintf(char *buf, size_t size, const char *format, va_list arg) 
{
	int written = 0;/*Number of characters written to the buffer*/
	size_t remaining = size > 0 ? size - 1 : 0;/*Remaining space in the buffer (excluding null-terminating character)*/

	while (*format != '\0' && remaining > 0) {
		if (*format == '%') {
			format++;/*Move past the '%'*/

			if (*format == '\0')
				break;/*Unexpected end of format string*/

			if (*format == '%') {
				/*Handle "%%" - output a single '%'*/
				if (remaining > 0) {
					*buf++ = '%';
					written++;
					remaining--;
				}
				format++;
				continue;
			}

			/*Handle other format specifiers*/
			/*Here, let's assume we only support "%s" for strings and "%d" for integers*/

			if (*format == 's') {
				char* arg_str = va_arg(arg, char*);
				while (*arg_str != '\0' && remaining > 0) {
					*buf++ = *arg_str++;
					written++;
					remaining--;
				}
				format++;
				continue;
			}

			if (*format == 'd') {
				int arg_int = va_arg(arg, int);
				/*Convert the integer to a string representation*/
				char int_str[12];/*Maximum number of characters for a 32-bit integer*/
				int chars_written = 0;
				bool is_negative = arg_int < 0;
				if (is_negative)
					arg_int = -arg_int;
				do {
					int digit = arg_int % 10;
					int_str[chars_written++] = '0' + digit;
					arg_int /= 10;
				} while (arg_int != 0);

				if (is_negative) {
					if (remaining > 0) {
						*buf++ = '-';
						written++;
						remaining--;
					}
				}

				while (chars_written > 0 && remaining > 0) {
					chars_written--;
					if (remaining > 0) {
						*buf++ = int_str[chars_written];
						written++;
						remaining--;
					}
				}

				format++;
				continue;
			}
		}

		/*Normal character - copy to the buffer*/
		if (remaining > 0) {
			*buf++ = *format++;
			written++;
			remaining--;
		}
	}

	/*Null-terminate the buffer*/
	if (size > 0)
		*buf = '\0';

	return written;
}
