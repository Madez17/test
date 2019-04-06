
#include <stdio.h>
int main(int argc, char * argv[])
{
	int iter;
	printf("%d\n", argc);

	for (iter = 1; argv[iter] != NULL; iter++)
	{
		printf("%s\n", argv[iter]);
	}
	return (0);
}
