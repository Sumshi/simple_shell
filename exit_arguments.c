#include "main.h"

void free_args(char **args);
/**
 * exit_arguments - a function that checks for exit errors
 * @argv: argument vectors
 * @args: arguments
 * @s: command pointer
 * @x: iterations counter
 * @exit_fail: exit failure status checker
 * @exit_status: the exit status
 * Return: void.
 */
void exit_arguments(char **argv, char **args, char *s, int x, int *exit_fail,
int *exit_status){
	unsigned int num;

	if (!args[1])
	{
		if (*exit_fail == 2 || *exit_status == 2)
		{
			free_args(args);
			free(s);
			exit(2);
		}
		if (*exit_status == 127)
		{
			free_args(args);
			free(s);
			exit(127);
		}
		else
		{
			free_args(args);
			free(s);
			exit(0);
		}
	}
	if (_isdigit(args[1]) == 1)
	{
		num = (unsigned int) _atoi(args[1]);
		if (num > (unsigned int) INT_MAX)
		{
			exit_error(argv[0], args, x);
			*exit_fail = 2;
			*exit_status = 2;
		}
		else
		{
			num %= 256;
			free_args(args);
			free(s);
			exit(num);
		}
	}
	else
	{
		exit_error(argv[0], args, x);
		*exit_fail = 2;
		*exit_status = 2;
	}
	free_args(args);
}

/**
 * free_args - Frees the memory allocated for an array of strings.
 * @args: Double pointer to an array of strings.
 *
 * Return: void.
 */
void free_args(char **args)
{
	char **arg_ptr = args;

	while (*arg_ptr)
	{
		free(*arg_ptr);
		arg_ptr++;
	}
	free(args);
}
