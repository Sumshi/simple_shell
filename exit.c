#include "main.h"
/**
 * exitShell - exits shell
 * @exitStatus: value
 * Return: always 0
 **/
void exitShell(int exitStatus)
{
	if (exitStatus < 0 || exitStatus > 255)
	{
		perror("invalid exit status");
	}
	exit(exitStatus);
}
