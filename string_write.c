#include "main.h"
/**
 * write_str - Writes a string to the buffer if space is available
 * @buf: The buffer to write to
 * @str: The string to write
 * @remaining: The remaining space in the buffer
 * @written: Pointer to the number of characters written
 */
void write_str(char **buf, const char *str, size_t *remaining, int *written)
{
	while (*str != '\0' && *remaining > 0)
	{
		write_character(buf, *str++, remaining, written);
	}
}
