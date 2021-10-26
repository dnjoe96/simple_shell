#include "shell.h"

/**
 * getpath - get the paths of the system from the environment
 * variables.
 *
 * @env: System environment
 * Return: Pointer to the first node of the list
 */
char **getpath(void)
{
	int i = 0;
	extern char **environ;
	char **paths;

	while (environ[i] != NULL)
	{
		
		if (environ[i][0] == 'P' && environ[i][1] == 'A' && environ[i][2] == 'T' && environ[i][3] == 'H')
		{
			paths = _strtok(environ[i], "=");

			paths = _strtok(paths[1], ":");

			break;
		}
	
		i++;
	}
	
	return (paths);
}

/**
 * commandpath - Find the path of a command
 *
 * @command: Command entered
 * Return: Full path of command if found, otherwise, return NULL
 */
char *commandpath(char *command)
{
	int i = 0;
	char *full, *full2;
	char **path;

	struct stat sb;

	path = getpath();

	while (path[i])
	{
		full = malloc(sizeof(char*));
		if (full == NULL)
			return (NULL);
		
		strcpy(full, path[i]);
		full = strcat(full, "/");
		full = strcat(full, command);

		if (stat(full, &sb) == 0)
			return (full);

		//printf("%s\n", full);
		i++;
		
	}

	return (NULL);
}

/**
int main(void)
{
	char *c = commandpath("cd");

	if (c == NULL)
		printf("Error, command not found\n");
	else
		printf("%s\n", c);

	return (0);
}
*/