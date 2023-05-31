#include "main.h"

char *int_to_str(int num);

/**
 * reverse_string - a function that reverse a string
 * @str: the given string
 * @length: the length of the string
 *
 * Return: void.
 */

void reverse_string(char *str, int length)
{
	char temp;
	int end, start = 0;

	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/**
 * int_to_str - a function converts a interger to a string
 * @num: the given integer
 *
 * Return: a pointer to the string.
 */
char *int_to_str(int num)
{
	char *str;
	int is_negative, length, digit, index, temp;

	if (num == 0)
	{
		str = (char *) malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	is_negative = 0;
	length = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	temp = num;
	while (temp > 0)
	{
		temp = temp / 10;
		length++;
	}
	if (is_negative)
	{
		length++;
	}
	str = (char *) malloc((length + 1) * sizeof(char));
	index = 0;
	while (num > 0)
	{
		digit = num % 10;
		str[index++] = digit + '0';
		num = num / 10;
	}
	if (is_negative)
	{
		str[index++] = '-';
	}
	str[index] = '\0';
	reverse_string(str, index);
	return (str);
}
