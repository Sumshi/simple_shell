#include "main.h"
/**
 * getLine - gets line
 * Return: bytes read
 **/
char *getLine()
{
	static char buffer[BUFFER_SIZE];
	static size_t position, bytesRead;
	char *line = NULL;
	size_t lineLength = 0, i;

	while (1)
	{
		if (position >= bytesRead)
		{
			bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			position = 0;
			if (bytesRead == 0)
			{
				break;
			}
			else if (bytesRead == (size_t)-1)
			{
				perror("Error from read");
				exit(EXIT_FAILURE);
			}
		}
		if (buffer[position] == '\n')
		{
			line = malloc((lineLength + 1) * sizeof(char));
			if (line == NULL)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
			for (i = 0; i < lineLength; i++)
			{
				line[i] = buffer[i];
			}
			line[lineLength] = '\0';
			position++;
			break;
		}
		lineLength++;
		position++;
	}
	return (line);
}
