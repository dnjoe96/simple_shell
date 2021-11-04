#include "shell.h"

/**
 * non_interactive - Executes the shell in non interactive mode
 * @path: Command path
 * @prog: Name of program
 *
 * Return: 0 on success
 */
int non_interactive(char **path, char *prog)
{
	char *line, *input;
	size_t len = 0;
	/*ssize_t read;*/
	char **argv;

	line = malloc(sizeof(char *));

	while (getline(&line, &len, stdin) != -1)
	{
		input = line;
		argv = _strtok(input, " \n\t");
		exec_func(argv, path, prog);
	}

	free(line);
	free(argv);

	return (0);
}
