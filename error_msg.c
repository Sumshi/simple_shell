#include "main.h"

/**
 * command_error - a function that checks for commands errors
 * @argv: argument vectors
 * @cmd: the given command
 * @count: the counter of main function
 * @check_path: check if the given command is a path or not
 * @exit_status: exit status of child process
 *
 * Return: void.
 */
void command_error(char *argv, char *cmd, int count, int check_path,
		int *exit_status)
{
	int y;
	char *num, *token;

	num = int_to_str(count);
	(void) y;
	if (check_path == 1)
	{
		token = strtok(cmd, "/");
		while (token)
		{
			cmd = token;
			token = strtok(NULL, "/");
		}
	}
	y = write(STDERR_FILENO, argv, _strlen(argv));
	y = write(STDERR_FILENO, ": ", 2);
	y = write(STDERR_FILENO, num, _strlen(num));
	y = write(STDERR_FILENO, ": ", 2);
	y = write(STDERR_FILENO, cmd, _strlen(cmd));
	y = write(STDERR_FILENO, ": ", 2);
	if (_strcmp(strerror(errno), "Permission denied") == 0)
	{
		perror("");
		*exit_status = 126;
	}
	else
	{
		y = write(STDERR_FILENO, "not found\n", 10);
		*exit_status = 127;
	}
	free(num);
}

/**
 * exit_error - a function that checks for exit errors
 * @argv: argument vectors
 * @args: command line
 * @count: the counter of main function
 *
 * Return: void.
 */
void exit_error(char *argv, char **args, int count)
{
	int y;
	char *num;

	num = int_to_str(count);
	(void) y;
	y = write(STDERR_FILENO, argv, _strlen(argv));
	y = write(STDERR_FILENO, ": ", 2);
	y = write(STDERR_FILENO, num, _strlen(num));
	y = write(STDERR_FILENO, ": ", 2);
	y = write(STDERR_FILENO, args[0], _strlen(args[0]));
	y = write(STDERR_FILENO, ": Illegal number: ", 18);
	y = write(STDERR_FILENO, args[1], _strlen(args[1]));
	y = write(STDERR_FILENO, "\n", 1);
	free(num);
}
