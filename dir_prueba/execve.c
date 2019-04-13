#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

main() {

    	pid_t my_pid;
	pid_t my_ppid;
	
    	my_pid = getpid();
	my_ppid = getppid();
    	printf("Child: %u\n", my_pid);
	printf("Parent: %u\n", my_ppid);

	execve("hello", *argv[], NULL);
	printf("Error");
}
