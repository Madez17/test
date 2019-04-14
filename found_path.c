#include "simple_shell.h"

/**
 * _found_path - Function
 *
 * @buffer: Buffer
 * @p: Doble pointer
 *
 * Return: Copy path
 */


char *_found_path(char *buffer, char **p)
{
	int iterenv, lenght;
	char *cpypath, *cpyenv;

	for (iterenv = 0; environ[iterenv] != NULL; iterenv++)
	{
		if (_strcmp(environ[iterenv], "PATH=", 5) == 0)
		{
			/*printf("%s ", environ[iterenv]);*/
			break;
		}
	}

	lenght = _strlen(environ[iterenv]);
	/*printf("%d\n", lenght);*/

	cpyenv = malloc(sizeof(char) * lenght + 1);
	if (cpyenv == NULL)
	{
		free(buffer);
		free(p);
		exit(-1);
	}
	cpypath = _strncpy(cpyenv, environ[iterenv], lenght);
	return (cpypath);
}

