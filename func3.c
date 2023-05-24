#include "main.h"
/**
 * _snprintf - writes formatted output to a string
 * @str: pointer to destination buffer
 * @size: maximum number of bytes to be used in the buffer
 * @format: format string
 * Return: number of characters that would have been written.
 */
int _snprintf(char *str, size_t size, const char *format, ...)
{
	va_list args;
	int ret;

	va_start(args, format);
	ret = vsnprintf(str, size, format, args);
	va_end(args);

	return (ret);
}
/**
 * _sprintf - writes formatted output to a string
 * @str: pointer to destination buffer
 * @format: format string
 * Return: number of characters that would have been written.
 */
int _sprintf(char *str, const char *format, ...)
{
	va_list args;
	int result;

	va_start(args, format);
	result = vsprintf(str, format, args);
	va_end(args);
	return (result);
}
