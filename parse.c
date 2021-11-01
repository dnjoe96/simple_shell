#include "shell.h"

/**
 * parse - perform command
 *
 * @argv: commands and options in array of strings
 * @path: paths from env variables
 */
int parse(char **argv, char **path)
{
        int i;
        char *check_path;

        command command_struct[] = {
                {"exit", _exitprog},
                {"cd", _cd},
                {"help", _help},
                {"env", print_env},
                {"others", fork_wait_exec},
        };

        check_path = commandpath(argv[0], path);

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

                                command_struct[i].execute(argv);
                        }
                        else
                                perror("Error");
                }
        }
        return (0);
}
