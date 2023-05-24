#include "main.h"
/**
 * exitShell - exits shell
 * @exitStatus: value
 * Return: always 0
 **/
void exitShell(int exitStatus)
{
	exit(exitStatus);
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
void handleVariables(char **args, int last_exit_status)
{
	int j;
	char pid[10];
	char exit_status[10];

	/*Replace $?, $$, and $PATH variables*/
	for (j = 0; args[j] != NULL; j++)
	{
		if (_strcmpr(args[j], "$?") == 0)
		{
			int len = int_to_string(exit_status, last_exit_status);
			write_string(args[j], exit_status, len);
		}
		else if (_strcmpr(args[j], "$$") == 0)
		{
			int len = int_to_string(pid, getpid());
			write_string(args[j], pid, len);
		}
		else if (_strcmpr(args[j], "$PATH") == 0)
		{
			args[j] = _strdup(getenv("PATH"));
		}
	}
}
void parseInput(char *input, char **args)
{
	char *token;
	int i = 0;

	token = _strtok(input, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = _strtok(NULL, " ");
	}
	args[i] = NULL;
}
