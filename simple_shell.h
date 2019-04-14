#ifndef FUNCTIONS_SHELL_H
#define FUNCTIONS_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<signal.h>

int _strcmp(char *s1, char *s2, int n);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *str_concat(char *s1, char *s2);
char *_prompt(char *buffer);
char **_store_args(char *buffer, int *cont);
int _exited(char *comm);
char **assign_args(char **p, int cont);
char *_found_path(char *buffer, char **p);


#endif /* FUNCTIONS_SHELL_H */
