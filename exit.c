#include "main.h"
/**
 * exitShell - exits shell
 * @exitStatus: value
 * Return: always 0
 **/
int exitShell(char **args, char **var)
{
	int i, len_int = 10;
	unsigned int n = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			i = 1;
			len_int++;
		}
		for (; args[0][i]; i++)
		{
			if (i <= len_int && args[0][i] >= '0' && args[0][i] <= '9')
				n = (n * 10) + (args[0][i] - '0');
			else
				return (print_error(--args, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (n > max - 1)
		return (print_error(--args, 2));
	args -= 1;
	free_args(args, var);
	free_env();
	free_alias_list(aliases);
	exit(n);
}
/**
 * isComment - checks for comments
 * @line: value
 * Return: line
 **/
int isComment(const char *line)
{
	return (line[0] == '#');
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
