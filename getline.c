#include "main.h"
/**
 * my_getline - getline() implementation
 * @lineptr: points to line pointer
 * @n: string
 * Return: line position
 */
ssize_t my_getline(char **lineptr, size_t *n) {
    static char buffer[BUFFER_SIZE];
    static int buffer_pos;
    static int buffer_size;
    char *line;
    size_t line_size;
    size_t line_pos;
    int newline_found;
    char c;

    if (*n == 0 || *lineptr == NULL)
    {
        return -1;
    }
    line = *lineptr;
    line_size = *n;
    line_pos = 0;
    newline_found = 0;

    while (1) {
        /*Check if buffer needs to be refilled*/
        if (buffer_pos >= buffer_size)
	{
            buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (buffer_size <= 0)
	    {
                if (line_pos == 0 || !newline_found)
		{
                    return -1;
                }
		else
		{
                    break;
                }
            }
            buffer_pos = 0;
        }

        c = buffer[buffer_pos++];
        if (line_pos + 1 >= line_size)
	{
            size_t new_line_size = line_size * 2;
            char *new_line = my_realloc(line, line_size, new_line_size);
            if (new_line == NULL)
	    {
                return -1;
            }
            line = new_line;
            line_size = new_line_size;
        }
        line[line_pos++] = c;

        if (c == '\n')
	{
            newline_found = 1;
            break;
        }
    }

    line[line_pos] = '\0';

    *lineptr = line;
    *n = line_size;

    return (line_pos);
}
