#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* string manipulator functions */
int _strcmp(char *str_1, char *str_2);
unsigned int _strlen(char *str);
char *_strdup(char *str);

/* string_tokenizing*/
char **_strtok(char *str, const char *delim);

/* getpath */
char **getpath(void);

#endif /* !SHELL_H */