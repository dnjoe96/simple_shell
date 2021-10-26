#include "shell.h"

/**
 * main - Creates a unix command line interpreter
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *commands = NULL;
	char **argv;
	int status;
	size_t bytes_read = 0;
	ssize_t chars_read;
	char *exit_cond = "exit";
	pid_t child_pid;

	write(STDOUT_FILENO, "$ ", 3);

	chars_read = getline(&commands, &bytes_read, stdin);
	if (chars_read == -1)
	{
		perror("Error: Could not read file_stream");
	}

	argv = _strtok(commands);

	while (_strcmp(argv[0], exit_cond) != 0)
	{
		/*argv = malloc(sizeof(char *) * array_size);
		if (argv == NULL)
		{
			perror("Error: Memory allocation failure\n");
			break;
		}

		tokens = strtok(commands, " \n");
		while (tokens != NULL)
		{
			argv[i] = tokens;
			tokens = strtok(NULL, " \n");
			i++;
		}
		argv[i] = NULL;*/
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: Failed to fork process!");
			break;
		}
		else if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");
		}
		else
			wait(&status);

		write(STDOUT_FILENO, "$ ", 3);

		chars_read = getline(&commands, &bytes_read, stdin);
		if (chars_read == -1)
		{
			perror("Error: Could not read file_stream");
		}

		argv = _strtok(commands);
	}

	if (_strcmp(argv[0], exit_cond) == 0)
			exit(EXIT_SUCCESS);

	return (0);
}
