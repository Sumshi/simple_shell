#include "main.h"
/**
 * write_integer - write integer to string
 * @str: Pointer to output string
 * @num: Integer number to write
 *
 * Return: Number of characters written
 */
int write_integer(char **str, int num)
{
	char num_str[12]; /*Adjust the size as needed*/
	int i, count;

	s_itoa(num, num_str);

	count = 0;

	for (i = 0; num_str[i]; i++)
	{
		*(*str)++ = num_str[i];
		count++;
	}

	return (count);
}
