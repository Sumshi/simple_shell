#include "main.h"

/**
 * ctrl_c - detect the CTRL+C signal and print another line with the prompt.
 * @x: idk.
 */
void ctrl_c(__attribute__((unused)) int x)
{
	signal(SIGINT, ctrl_c);
	write(1, "\n", 1);
	write(STDOUT_FILENO, "\033[0;36mhsh# \033[0m", 16);
}

/**
 * print_error - print specific errors to standard output.
 * @program_name: argv[0] of main.
 *
 * @error_num: error number - identifies the error type.
 */
int print_error(char **program_name, int error_num)
{
	char *error;

	switch (error_num)
	{
		case -1:
			error = error_env(program_name);
			break;
		case 1:
			error = error_1(program_name);
			break;
		case 2:
			if (*(program_name[0]) == 'e')
				error = error_2_exit(++program_name);
			else if (program_name[0][0] == ';' || program_name[0][0] == '&' || program_name[0][0] == '|')
				error = error_2_syntax(program_name);
			else
				error = error_2_cd(program_name);
			break;
		case 126:
			error = error_126(program_name);
			break;
		case 127:
			error = error_127(program_name);
			break;
	}
	write(STDERR_FILENO, error, _strlen(error));

	if (error)
		free(error);
	return (error_num);
}
