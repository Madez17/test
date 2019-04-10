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
	size_t sizebuf = 0;
	ssize_t characters;
	int iter;
	int cont;
	int iter2;
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
		write(1, "#cisfun$ ", 9);

		characters = getline(&buffer, &sizebuf, stdin);
		iter = 0;
		cont = 0;
		if (characters == EOF)
		{
			perror("./shell");
			exit(-1);
		}
		while (buffer[iter] != '\0')
		{
			if (buffer[iter] == ' ' || buffer[iter] == '\n')
			{
				cont++;
			}
			iter++;
		}
		cont++;
		/*printf("Iteraciones: %d\n", iter);
		printf("N de palabras: %d\n", cont);*/
		p = malloc(sizeof(char *) *cont);
		p[0] = strtok(buffer, " \n");
		/*printf("%s ", p[0]);*/
		iter2 = 1;
		while (iter2 < cont)
		{
			p[iter2] = strtok(NULL, " \n");
			/*printf("%s ", p[iter2]);*/
			iter2++;
		}

		if (fork() == 0)
		{
			if (execve(p[0], p, NULL) == -1)
			{		
				perror("./shell");
				exit(-1);
			}
			
		}

		wait(NULL);
	}
	return(0);
}
