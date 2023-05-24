#include "main.h"
/**
 * executeCommand - executes a command
 * @cmd: command to execute
 * @args: arguments passed
 * Return: Always 0.
 */
int executeCommand(char *cmd, char **args)
{
	char *absolutePath = getAbsolutePath(cmd);
	pid_t pid;
	int status;

	if (absolutePath == NULL)
	{
		/*command not found || error occured*/
		return (-1);
	}

	if (access(absolutePath, X_OK) != 0)
	{
		free(absolutePath);
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(absolutePath);
		return (-1);
	}
	else if (pid == 0)
	{
		execve(absolutePath, args, NULL);
		perror("execve");
		free(absolutePath);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(absolutePath);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else
		{
			return (-1);
		}
	}
}
