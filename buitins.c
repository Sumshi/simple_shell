#include "main.h"
/**
 * check_exit - checks exit
 * @args: argument vector
 * Return: void
 */
void check_exit(char **args)
{
	int stats;

	stats = EXIT_SUCCESS;
	if (args[1] != NULL && args[1][0] != '\0')
	{
		char *endptr;
		long val = strtol(args[1], &endptr, 10);

		if (*endptr != '\0' || val > INT_MAX || val < INT_MIN)
		{
			fprintf(stderr, "Invalid argument: %s\n", args[1]);
			return;
		}

		stats = (int)val;
	}
	exit(stats);
}
/**
 * set_env - sets environment
 * @args: argument vector
 * Return: void
 */
void set_env(char **args)
{
	char *msg;

	if (args[1] == NULL || args[2] == NULL)
	{
		msg = "Usage: setenv VARIABLE VALUE\n";
		write(STDOUT_FILENO, msg, _strlen(msg));
	}
	if (mySetEnv(args[1], args[2]) != 0)
	{

	}
}
/**
 * unset_env - unsets environment
 * @args: argument vector
 * Return: void
 */
void unset_env(char **args)
{
	char *msg;

	if (args[1] == NULL)
	{
		msg = "Usage: unsetenv VARIABLE\n";
		write(STDOUT_FILENO, msg, _strlen(msg));
	}
	if (myUnsetEnv(args[1]) != 0)
	{

	}
}
