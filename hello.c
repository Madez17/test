#include <stdio.h>
#include <stdlib.h>
main(int argc,char *argv[],char *envp[])
{
	
    	pid_t my_pid;
	pid_t my_ppid;
    	my_pid = getpid();
	my_ppid = getppid();
	
	printf("Child: %u\n", my_pid);
	printf("Parent: %u\n", my_ppid);

	char *pinterbf;
	size_t bufsize = 1;
	size_t characters = 0;	

	pinterbf = malloc(sizeof(char) * bufsize);
	printf("$ ");

	while(characters != EOF)
	{
		characters = getline(&pinterbf, &bufsize, stdin);
		printf("%s", pinterbf);
		printf("%zu Estamos ejecutando un proceso desde otro %lu\n", characters, bufsize);
	  	bufsize = 1;
	}

	return (0);
}
