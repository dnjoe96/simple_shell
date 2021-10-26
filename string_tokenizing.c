#include "shell.h"

/**
 * _strtok - Breaks a string into a sequence of tokens
 * @str: String to be broken into tokens
 *
 * Return: Array of the tokens
 */

char **_strtok(char *str)
{
	char *tokens;
	char **argv;
	int i = 0, array_size = 1024;

	tokens = strtok(str, " \n");
	argv = malloc(sizeof(char *) * array_size);
	if (argv == NULL)
		return (NULL);

	while (tokens != NULL)
	{
		argv[i] = tokens;
		tokens = strtok(NULL, " \n");
		i++;
	}
	argv[i] = NULL;

	return (argv);
}
