#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *pinterbf;
	size_t bufsize = 1;
	size_t characters = 0;

	pinterbf = malloc(sizeof(char) * bufsize);
	printf("$ ");

	while(characters != EOF)
	{
	  characters = getline(&pinterbf, &bufsize, stdin);
	  printf("%s", pinterbf);
	  printf("%zu characters were read.%lu\n",characters, bufsize);
	  bufsize = 1;
	}

	return (0);
}
