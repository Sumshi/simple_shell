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
    int i;
    char pid[10];
    char exit_status[10];

    for (i = 0; args[i] != NULL; i++)
    {
        if (_strcmpr(args[i], "$?") == 0)
        {
            int len = int_to_string(exit_status, last_exit_status);
            write_string(args[i], exit_status, len);
        }
        else if (_strcmpr(args[i], "$$") == 0)
        {
            int len = int_to_string(pid, getpid());
            write_string(args[i], pid, len);
        }
        else if (args[i][0] == '$')
        {
            char *variable = &args[i][1];
            char *value = getenv(variable);
            if (value != NULL)
            {
                args[i] = _strdup(value);
                if (args[i] == NULL)
                {
                    fprintf(stderr, "Error: Memory allocation failed\n");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                fprintf(stderr, "Error: Variable '%s' is undefined\n", variable);
            }
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
