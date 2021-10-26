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
