#include "main.h"
/**
 * write_float_decimal - writes double to string
 * @str: pointer to output string
 * @num: Double number to write
 *
 * Return: Number of characters written
 */
int write_float_decimal(char **str, double num)
{
	/*Number of decimal places to display*/
	const int MAX_DECIMAL_PLACES = 6;
	int count, i, digit;

	/*Write decimal point to string*/
	*(*str)++ = '.';

	/*Increment counter*/
	count = 1;

	/*Write each decimal digit to string*/
	for (i = 0; i < MAX_DECIMAL_PLACES; i++)
	{
		num *= 10;
		digit = (int)num;

		*(*str)++ = digit + '0';

		num -= digit;

		count++;
	}

	return (count);
}
