#ifndef FUNCTIONS_SHELL_H
#define FUNCTIONS_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int _strcmp(char *s1, char *s2, int n);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *str_concat(char *s1, char *s2);

#endif /* FUNCTIONS_SHELL_H */
