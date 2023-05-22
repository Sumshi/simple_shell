#include "main.h"

/**
 * write_int- Writes an integer to the buffer if space is available
 * @buf: The buffer to write to
 * @value: The integer value to write
 * @remaining: The remaining space in the buffer
 * @written: Pointer to the number of characters written
 */
void write_int(char **buf, int value, size_t *remaining, int *written)
{
	char int_str[12];
	int chars_written = 0;
	bool is_negative = value < 0;

	if (is_negative)
		value = -value;
	do {
		int digit = value % 10;

		int_str[chars_written++] = '0' + digit;
		value /= 10;
	} while (value != 0);

	if (is_negative)
		write_character(buf, '-', remaining, written);

	while (chars_written > 0 && *remaining > 0)
	{
		chars_written--;
		write_character(buf, int_str[chars_written], remaining, written);
	}
}
