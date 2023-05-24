#include "main.h"
/**
 * parseInput - tokenizes the input
 * @input: input passed.
 * @args: arguments passes
 * Return: Always 0.
 */
void parseInput(char *input, char **args)
{
	char *token;
	int i = 0;

	token = _strtok(input, " ");
	while (token != NULL)
	{
		char *output = handleVariables(token);

		args[i++] = output;

		token = _strtok(NULL, " ");
	}
	args[i] = NULL;
}
/**
 * handleVariables - handles $, $$
 * @input: input passed.
 * Return: Always 0.
 */
char *handleVariables(char *input)
{
	char *output = NULL;
	int last_exit_status = 0;

	if (_strcmpr(input, "$") == 0)
	{
		output = getenv("HOME");
	}
	else if (_strcmpr(input, "$$") == 0)
	{
		int pid = getpid();

		output = malloc(sizeof(char) * 16);
		sprintf(output, "%d", pid);
	}
	else if (_strcmpr(input, "$PATH") == 0)
	{
		output = getenv("PATH");
	}
	else if (_strcmpr(input, "$?") == 0)
	{

		output = malloc(sizeof(char) * 16);
		sprintf(output, "%d", last_exit_status);
	}
	else
	{
		output = _strdup(input);
	}
	return (output);
}
