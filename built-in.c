#include "shell.h"

/**
 * _cd - function to implement change directory
 *
 * @args: command arguements
 * Return
 */
int _cd(char **args)
{
	if (args[1] == NULL)
	{
		write(2, "lsh: expected argument to \"cd\"\n", 31);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}

	free(args);
	return 1;
}

/**
 * _help - to display shell usage
 * now it is hard coded, but as we progress, we will be reading
 * from a file
 *
 * Return: Int
 */
int _help(char **args)
{
	write(1, "Joseph & Washington shell\n", 26);
	write(1, "Type program names and arguments, and hit enter.\n", 49);
	write(1, "The following are built in:\n", 28);
	write(1, "* cd\n", 5);
	write(1, "* help\n", 7);
	write(1, "* exit\n", 7);
	write(1, "\nUse the man command for information on other programs.\n", 57);

	free(args);
	return 1;
}

/**
 * _exit - The  function that would exit the program
 */
int _exitprog(char **args)
{
	free(args);
	exit(0);
	return 0;
}

/**
 * print_env - Prints the current environment
 * argv: Command env
 *
 * Return: Nothing
 */
int print_env(char **argv)
{
	extern char **environ;
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	free(argv);
	return (0);
}
