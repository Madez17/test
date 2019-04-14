#include "simple_shell.h"

/**
 * _prompt - get parameters in the promt
 *
 * @buffer: space in memory
 *
 * return: buffer
 */

char *_prompt(char *buffer)
{
	ssize_t characters;
	size_t sizebuf = 120;

	write(1, "#cisfun$ ", 9);
	characters = getline(&buffer, &sizebuf, stdin);
	if (characters == EOF)
	{
		perror("./shell");
		free(buffer);
		exit(-1);
	}

	return (buffer);

}
