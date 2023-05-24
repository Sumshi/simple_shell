#include "main.h"
/**
 * getAbsolutePath - gets the absolute path of a command
 * @command: command to execute
 * Return: Absolute path of the command if found, otherwise NULL.
 */
char *getAbsolutePath(char *command)
{
	const int MAX_PATHS = MAX_ARGS + 2;
	char *pathDirectory[MAX_PATHS];
	int numDirectory = 0, i, j;
	char *token, *pathEnvVar;
	char tempCmd[BUFFER_SIZE];
	char *pathEnvCopy;

	if (command[0] == '/')
	{
		return (_strdup(command));
	}
	pathDirectory[numDirectory++] = "/bin"; /* add /bin to search path */
	pathEnvVar = getenv("PATH");
	if (pathEnvVar == NULL)
	{
		return (NULL);
	}
	pathEnvCopy == _strdup(pathEnvVar);
	if (pathEnvCopy == NULL)
	{
		return (NULL);
	}

	token = _strtok(pathEnvVar, ":");
	while (token != NULL && numDirectory < MAX_PATHS - 1)
	{
		pathDirectory[numDirectory++] = _strdup(token);
		token = _strtok(NULL, ":");
	}
	pathDirectory[numDirectory] = NULL;
	for (i = 0; i < numDirectory; i++)
	{
		int pathLen = _strlen(pathDirectory[i]);
		int cmdLen = _strlen(command);

		if (pathLen + cmdLen + 2 > BUFFER_SIZE)
		{ /* Check if the combined length exceeds buffer size */
			continue;
		}
		_strcpy(tempCmd, pathDirectory[i]);
		tempCmd[pathLen] = '/';
		_strcpy(tempCmd + pathLen + 1, command);
		if (access(tempCmd, X_OK) == 0)
		{
			free(pathEnvCopy);
			for (j = 0; j < numDirectory; j++)
			{
				free(pathDirectory[j]);
			}
			return (_strdup(tempCmd));
		}
	}
	free(pathEnvCopy);
	for (j = 0; j < numDirectory; j++)
	{
		free(pathDirectory[j]);
	}
	return (NULL);
}
