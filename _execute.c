#include "shell.h"

/**
 * _execute - allows execution of a command though
 *                       its name or its full path
 * @argv: commands to be executed
 * @path: Full path of the command to be executed
 *
 * Return: Nothing
 */
void _execute(char **argv, char **path)
{

	if (argv[0][0] == '.' || argv[0][0] == '/')
		fork_wait_exec(argv);
	else
		exec_func(argv, path);
}
