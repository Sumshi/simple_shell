#include "main.h"
/**
 * printPrompt - prints a prompt to the console
 * Return: always 0
 */
void printPrompt(void)
{
	/*if (isatty(STDIN_FILENO) == 1)reads from terminal*/
		write(STDOUT_FILENO, "$ ", 2);
}
