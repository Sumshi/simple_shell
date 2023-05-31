#include "main.h"

/**
 * command_split - a function that splits the command line.
 * @str: a pointer to the command line
 *
 * Return: an array of strings
 */
char **command_split(char *str)
{
	char *token, *token_hash, **args;
	int i, y, number_comands;

	(void) y;
	number_comands = 0;
	if (str[0] != ' ' && str[0] != '\t' && str[0] != '\n')
		number_comands++;
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != ' '
				&& str[i + 1] != '\t' && str[i + 1] != '\n')
			number_comands++;
	}
	if (number_comands == 0)
		return (NULL);
	args = malloc((number_comands + 1) * sizeof(char *));
	if (args == NULL)
	{
		y = write(STDERR_FILENO, "Error: malloc failed\n", 22);
		free(str);
		exit(98);
	}
	token_hash = strtok(str, "#");
	token = strtok(token_hash, DELIM);
	i = 0;
	while (token)
	{
		args[i] = _strdup(token);
		if (args[i] == NULL)
		{
			y = write(STDERR_FILENO, "Error: malloc failed\n", 22);
			free_args(args);
			exit(98);
		}
		token = strtok(NULL, DELIM);
		i++;
	}
	args[number_comands] = NULL;
	return (args);
}
