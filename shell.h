#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/**
 * struct command - A string - function pair
 *
 * @buf:  the command
 * @print: Special function implemented to print data of a given
 * specifier to stdout
 *
 * Description: A specifier - function pair
 */
typedef struct
{
	char *buf;
	int (*execute)(char **args);
} command;


/* string manipulator functions */
int _strcmp(char *str_1, char *str_2);
unsigned int _strlen(char *str);
char *_strdup(char *str);

/* string_tokenizing*/
char **_strtok(char *str, const char *delim);

/* getpath */
char **getpath(void);
char *commandpath(char *command);

/* built-in functions */
int _cd(char **args);
int _exitprog(char **args);
int _help(char **args);

#endif /* !SHELL_H */
