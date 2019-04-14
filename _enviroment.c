#include "simple_shell.h"

/**
* _env - Function
*
* @p: doble pointer
*
* Return: Always 0 (Success)
*
*/

int _env(char **p)
{
	int iterenv;
	int lenght;

	if ((_strlen(p[0]) - 3) >= 0)
	{
		if (_strcmp(p[0], "env", 3) == 0)
		{
			for (iterenv = 0; environ[iterenv] != NULL; iterenv++)
			{
				lenght = _strlen(environ[iterenv]);
				write(1, environ[iterenv], lenght);
				write(1, "\n", 1);
			}
			return (1);
		}
	}
	return (0);
}
