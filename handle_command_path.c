#include "shell.h"

/**
 * handle_command_path - allows execution of a command or its full path
 *
 * Return: Nothing
 */
void handle_command_path(char **argv, char **path)
{

	if (argv[0][0] == '.' || argv[0][0] == '/')
		fork_wait_exec(argv);
	else
		parse(argv, path);
}
