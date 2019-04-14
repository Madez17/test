#include "simple_shell.h"

/**
*
*
*
*/

if((_strlen(p[0]) - 3) >= 0)
{
	if (_strcmp(p[0], "env", 3) == 0)
	{
		for (iterenv = 0; environ[iterenv] != NULL; iterenv++)
		{	
			lenght = _strlen(environ[iterenv]);
			/*printf("%s", environ[iterenv]);
			printf("%d", lenght);*/
			write(1, environ[iterenv], lenght);
			write(1, "\n", 1);
		}
		own_comm = 0;
	}
}
