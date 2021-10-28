#include "shell.h"

/**
 * main - Creates a unix command line interpreter
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *commands, *check_path;
	char **argv;
	char **path;
	size_t bytes_read = 1;
	ssize_t chars_read;
	char *exit_cond = "exit";

	/**
	set commands[] = {
		{"exit", _exitprog},
		{"cd", _cd},
		{"help", _help},
		{"others", fork_wait_exec},
	};
	*/

	path = getpath();
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 3);

		commands = malloc(sizeof(char *));
		chars_read = getline(&commands, &bytes_read, stdin);
		if (chars_read == -1)
		{
			perror("Error: Could not read file_stream");
		}

		/*commands[_strlen(commands) - 1] = '\0';*/

		argv = _strtok(commands, " \n\t");
		/*free(commands);*/

		if (_strcmp(argv[0], exit_cond) == 0)
			break;
		/*free(commands);*/

		check_path = commandpath(argv[0], path);
		/*printf("check_path = %s\n", check_path);*/
		if (check_path != NULL)
		{
			argv[0] = check_path;
			fork_wait_exec(argv);
		}
		else
			perror("Error");
		free(commands);
	}

	if (commands != NULL)
		free(commands);
	if (argv != NULL)
		free(argv);

	return (0);
}
