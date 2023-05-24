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
