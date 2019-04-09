#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 *
 *
 */

int main(int argc, char *argv[])
{
	char *buffer;
	size_t sizebuf = 1;
	ssize_t characters;
	int iter = 0;
	int cont = 0;
	int iter2 = 1;
	char **p;
	pid_t my_pid;
	pid_t my_ppid;
	
    	my_pid = getpid();
	my_ppid = getppid();

	buffer = malloc(sizeof(char *) * 1024);
	if (!buffer)
		return (0);

	while (1)
	{

		printf("$ ");

		characters = getline(&buffer, &sizebuf, stdin);

		while (buffer[iter] != '\0')
		{
			if (buffer[iter] == ' ' || buffer[iter] == '\n')
			{
				cont++;
			}
			iter++;
		}
		cont + 1;

		p = malloc(sizeof(char *) *cont);
		p[0] = strtok(buffer, " \n");

		while (iter2 < cont)
		{
			p[iter2] = strtok(NULL, " \n");
			iter2++;
		}

		if (fork() == 0)
		{
			if (execve(p[0], p, NULL) == -1)
			{
				printf("./shell: No such file or directory\n");
			}
			
		}
		wait(NULL);
	}
	return(0);
}
