#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[], char *envp[])
{
	extern char **environ;
	int iter = 0;

	while (environ[iter] != NULL)
	{
		printf("%s\n", environ[iter]);
		iter++;

	}
	return (0);
}

