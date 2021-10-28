#include "shell.h"

/**
 * main - Creates a unix command line interpreter
 *
 * Return: Always 0 (success)
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	int i;
	char *commands, *check_path;
	/*char **argv;*/
	char **path;
	size_t bytes_read = 1;
	ssize_t chars_read;
	char *exit_cond = "exit";

	command command_struct[] = {
		{"exit", _exitprog},
		{"cd", _cd},
		{"help", _help},
		{"env", print_env},
		{"others", fork_wait_exec},
	};

	path = getpath();
	while (1 && argc == 1)
	{
		write(STDOUT_FILENO, "$ ", 3);

		commands = malloc(sizeof(char *));
		chars_read = getline(&commands, &bytes_read, stdin);
		if (chars_read == -1)
		{
			perror("Error: Could not read file_stream");
		}

		if (commands[0] == '\n')
			continue;
		
		commands[_strlen(commands) - 1] = '\0';

		argv = _strtok(commands, " \t");
		/*free(commands);*/

		if (strcmp(argv[0], exit_cond) == 0)
			break;
		/*free(commands);*/

		check_path = commandpath(argv[0], path);
		/*printf("check_path = %s\n", check_path);*/
		
		for (i = 0; i < 5; i++)
		{
			if (strcmp(argv[0], command_struct[i].buf) == 0)
			{
				command_struct[i].execute(argv);
				break;
			}

			if (i == 4)
			{
				if (check_path != NULL)
				{
					argv[0] = check_path;
					/*fork_wait_exec(argv);*/
					command_struct[i].execute(argv);
				}
				else
					perror("Error");
			}
		}
	/*	
		if (commands != NULL)
			free(commands);
		if (argv != NULL)
			free(argv);
	*/
	}

	if (commands != NULL)
		free(commands);
	if (argv != NULL)
		free(argv);

	return (0);
}
