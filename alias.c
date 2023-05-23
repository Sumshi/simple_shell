#include "main.h"
Alias aliases[MAX_ALIASES];
int num_aliases = 0;
/**
 * printAliases - Prints all the available aliases
 */
void printAliases(void)
{
	if (num_aliases == 0)
	{
		write(STDOUT_FILENO, "No aliases defined.\n", 20);
		return;
	}

	for (int i = 0; i < num_aliases; i++)
	{
		char buffer[256];
		int size = _sprintf(buffer, "%s=%s\n", aliases[i].name, aliases[i].value);
		write(STDOUT_FILENO, buffer, size);
	}
}

/**
 * printAlias - Prints the specified alias
 * @name: Name of the alias to be printed
 */
void printAlias(char *name)
{
	for (int i = 0; i < num_aliases; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			char buffer[256];
			int size = _sprintf(buffer, "%s=%s\n", aliases[i].name, aliases[i].value);
			write(STDOUT_FILENO, buffer, size);
			return;
		}
	}

	char buffer[256];
	int size = _sprintf(buffer, "Alias '%s' not found.\n", name);
	write(STDOUT_FILENO, buffer, size);
}

/**
 * addAlias - Adds a new alias or updates an existing one
 * @name: Name of the alias to be added/updated
 * @value: Value of the alias to be added/updated
 */
void addAlias(char *name, char *value)
{
	for (int i = 0; i < num_aliases; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			free(aliases[i].value);
			aliases[i].value = _strdup(value);

			char buffer[256];
			int size = _sprintf(buffer, "Alias '%s' updated.\n", name);
			write(STDOUT_FILENO, buffer, size);
			return;
		}
	}

	if (num_aliases >= MAX_ALIASES)
	{
		write(STDOUT_FILENO, "Too many aliases defined.\n", 27);
		return;
	}

	aliases[num_aliases].name = _strdup(name);
	aliases[num_aliases].value = _strdup(value);
	num_aliases++;

	char buffer[256];
	int size = _sprintf(buffer, "Alias '%s' created.\n", name);
	write(STDOUT_FILENO, buffer, size);
}

/**
 * executeAlias - Executes the specified alias
 * @name: Name of the alias to be executed
 */
void executeAlias(char *name)
{
	for (int i = 0; i < num_aliases; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			char *command = aliases[i].value;
			char *command_args[] = {command, NULL};
			execve(command, command_args, NULL);

			perror("Failed to execute the aliased command");
			return;
		}
	}

	char buffer[256];
	int size = _sprintf(buffer, "Alias '%s' not found.\n", name);
	write(STDOUT_FILENO, buffer, size);
}

/**
 * aliasCommand - Parses and executes the given alias command
 * @args: Array of arguments passed to the alias command
 */
void aliasCommand(char **args)
{
	if (args[1] == NULL)
	{
		printAliases();
		return;
	}

	int i = 1;
	while (args[i] != NULL)
	{
		char *arg = args[i];
		int j = 0;

		while (arg[j] != '\0' && arg[j] != '=')
		{
			j++;
		}

		if (arg[j] == '=')
		{
			arg[j] = '\0';
			addAlias(arg, arg + j + 1);
		}
		else
			executeAlias(arg);

		i++;
	}
}
