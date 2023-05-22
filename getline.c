#include "main.h"
/**
 * myGetLine - my getline function
 *
 * Return: Always 0.
 */
char *myGetLine(void)
{
	static char buffer[BUFFER_SIZE];
	static int pos, bytesRead;
	char *line = NULL;
	int lineSize = 0;
	char c;

	while (1)
	{
		if (pos == bytesRead)
		{
			bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (bytesRead == -1)
			{
				perror("Error from read");
				exit(EXIT_FAILURE);
			}
			if (bytesRead == 0)
			{
				break;
			}
			pos = 0;/*Reset position to start of buffer*/
		}
		c = buffer[pos++];
		if (c == '\n')
		{
			line[lineSize] = '\0';
			break;
		}
		line = my_realloc(line, lineSize, lineSize + 1);
		line[lineSize - 1] = c;
	}
	return (line);
}
