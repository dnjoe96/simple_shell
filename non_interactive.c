#include "shell.h"

/**
 * interactive - Executes the shell in non interactive mode
 * @path: Command path
 * @prog: Name of program
 *
 * Return: 0 on success
 */
int non_interactive(char **path, char *prog)
{
	char *buffer;
	int bytes_read;
	size_t count = 1024;
	char **buf, **str;
	int i = 0;

	buffer = malloc(sizeof(char *) * count);
	bytes_read = read(STDIN_FILENO, buffer, count);
	if (bytes_read == -1)
		perror("Error");
	/*printf("%d\n", bytes_read);*/

	/*write(1, buffer, count);*/
	buf = malloc(sizeof(char *) * count);
	if (buf == NULL)
		printf("Error");
	buf = _strtok(buffer, "\n");

	/*write(1, "\n", 2);*/

	while (buf[i])
	{
		str = _strtok(buf[i], " \t");
		exec_func(str, path, prog);
		/*write(1, buf[i], _strlen(buf[i]));
		  write(1, "\n", 2);*/
		i++;
	}

	free(buffer);
	free(buf);
	return (0);
}
