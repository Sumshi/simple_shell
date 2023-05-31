#include "main.h"

/**
 * env_args - Print environment variables.
 * @args: Double pointer to an array of strings containing arguments.
 *
 * Return: void.
 */
void env_args(char **args)
{
	char **env, *str;
	ssize_t y;

	(void) y;
	if (args[1] != NULL)
	{
		str = "env: ‘";
		y = write(STDERR_FILENO, str, _strlen(str));
		y = write(STDERR_FILENO, args[1], _strlen(args[1]));
		str = "’: No such file directory\n";
		y = write(STDERR_FILENO, str, _strlen(str));
	}
	else
	{
		env = environ;
		while (*env)
		{
			y = write(1, *env, _strlen(*env));
			y = write(1, "\n", 2);
			env++;
		}
	}
}
