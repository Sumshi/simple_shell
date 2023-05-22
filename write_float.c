#include "main.h"
/**
 * write_float - write float to string
 * @str: pointer to output string
 * @num: float number to write
 * Return: Number of characters written
 */
int write_float(char **str, float num)
{
	double dec_part;

	/*Extract integer and decimal parts*/
	int int_part = (int)num;

	if (num < 0)
	{
		dec_part = -(num - int_part);
		int_part *= -1;

		/*Write negative sign to string*/
		*(*str)++ = '-';

		/*Increment counter*/
		return (write_integer(str, int_part) + write_float_decimal(str, dec_part));

	}
	else
	{
		dec_part = num - int_part;

		/*Write positive number to string*/
		return (write_integer(str, int_part) + write_float_decimal(str, dec_part));
	}
}
