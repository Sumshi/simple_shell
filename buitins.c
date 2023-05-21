#include "main.h"
void check_exit(char **args)
{
	int stats;

	stats = EXIT_SUCCESS;
	if (args[1] != NULL)
	{
		stats = _atoi(args[1]);
	}
	exit(stats);
}
