#include <stdio.h> 
#include <string.h> 
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COUNT 1

void childProcess(void);
void parentProcess(void);

void ChildProcess(void)
{
	int i;
	for (i = 1; i <= MAX_COUNT; i++)
	{
		printf("Esta línea es de hijo, valor = %d\n", i);
		printf("*** El proceso hijo se realiza ***\n");
	}
}
void ParentProcess (void) 
{
	int i;
	
	for (i = 1; i <= MAX_COUNT + 1; i++)
		printf ("Esta línea es de padre, valor = %d\n", i);
		printf ("*** padre está hecho ***\n"); 
}
void main(void)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		ChildProcess();
	else
		ParentProcess();
}

