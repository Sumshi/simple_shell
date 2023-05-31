#include "main.h"

/**
 * _getenv - Get the value of an environment variable.
 * @variable_name: Pointer to a null-terminated string representing
 * the name of the environment variable.
 *
 * Return: NULL pointer.
 */
char *_getenv(char *variable_name)
{
	int i;
	size_t name_length = _strlen(variable_name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], variable_name, name_length) == 0
			&& environ[i][name_length] == '=')
		{
			return (environ[i] + name_length + 1);
		}
	}

	return (NULL);
}
