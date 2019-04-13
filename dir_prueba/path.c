#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char *argv[])
{
	struct stat fileStat;
	int answer;

	answer = stat("mafe.txt", &fileStat);

	if (answer < 0)
	{
		perror(NULL);
	}
	printf("---------------------------\n");
	printf("File size: \t\t %d bytes\n", fileStat.st_size);
}
