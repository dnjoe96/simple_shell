#include "shell.h"

/**
 * main - Creates a unix command line interpreter
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *commands;
	char **argv;
	int status;
	size_t bytes_read = 1;
	ssize_t chars_read;
	char *exit_cond = "exit";
	pid_t child_pid;

	/**
	set commands[] = {
		{"exit", _exitprog},
		{"cd", _cd},
		{"help", _help},
		{"others", _others},
	};
	*/

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

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: Failed to fork process!");
			break;
		}

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");
			exit(0);
			/*free(argv);*/
		}
		else
			wait(&status);
		free(commands);
		free(argv);

	}

	if (commands != NULL)
		free(commands);
	if (argv != NULL)
		free(argv);

	return (0);
}
