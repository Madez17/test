#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
* _strcmp - concatenacion.
*
* @s1: dest array
*
* @s2: array
*
* Return: Always 0.
*/
int _strcmp(char *s1, char *s2)
{
	int result;
	int cont;

	for (cont = 0; s1[cont] != '\0' && cont < 5; cont++)
	{
		result = s1[cont] - s2[cont];

		printf("%d\n", result);
		if (result != 0)
		{
			printf("Estamos aqui");
			return(1);
		}
	}
	
	return (0);
}

/**
* _strlen - Exchange the value
*
* @s: Value string
*
* Return: Always 0.
*/
int _strlen(char *s)
{
	int length;

	for (length = 0; *s != '\0'; s++)
		length++;
	return (length);
}

/**
  * _strncpy - concatenacion.
  *
  * @dest: dest array
  *
  * @src: array
  *
  * @n: position
  *
  * Return: Always 0.
  */
char *_strncpy(char *dest, char *src, int n)
{
	char cont;

	for (cont = 0; src[cont] != '\0' && cont < n; cont++)
	{
		dest[cont] = src[cont];

	}
	for (; cont < n; cont++)
		dest[cont] = '\0';
	return (dest);
}

/**
 * str_concat - Duplicate string
 * @s1: string one
 * @s2: string two
 * Return: pointer to copy array
 */
char *str_concat(char *s1, char *s2)
{
	char *p;
	unsigned int i;
	unsigned int size_s1, size_s2;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (size_s1 = 0; *(s1 + size_s1) && s1; size_s1++)
	{
	}
	for (size_s2 = 0; *(s2 + size_s2) && s2; size_s2++)
	{
	}
	p =  malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i < size_s1 + size_s2; i++)
	{
		if (i < size_s1)
			p[i] = *(s1 + i);
		else
			p[i] = *(s2 + i - size_s1);
	}
	p[i] = '\0';
	return (p);
}


/**
 *
 * main - Function
 *
 */

int main(int argc, char *argv[])
{
	extern char **environ;
	char *buffer;
	char *cpyenv;
	char *cpypath;
	char  *result;
	char *concat;
	size_t sizebuf = 0;
	ssize_t characters;
	int iter, cont, iter2, iterenv, lenght;
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

		if(!p)
			return (0);

		p[0] = strtok(buffer, " \n");

		if (_strcmp(p[0], "exit") == 0)
		{
			exit(-1);
		}

		/*printf("%s ", p[0]);*/
		iter2 = 1;
		while (iter2 < cont)
		{
			p[iter2] = strtok(NULL, " \n");
			/*printf("%s ", p[iter2]);*/
			iter2++;
		}

		concat = p[0];

		if (access(p[0], F_OK) != 0)
		{
			
			for (iterenv = 0; environ[iterenv] != NULL; iterenv++)
			{
				if (_strcmp(environ[iterenv], "PATH=") == 0)
				{
					/*printf("%s ", environ[iterenv]);*/
					break;
				}
			}

			lenght = _strlen(environ[iterenv]);
			/*printf("%d\n", lenght);*/

			cpyenv = malloc(sizeof(char) * lenght + 1);
			
			if (!cpyenv)
				return (0);

			cpypath = _strncpy(cpyenv, environ[iterenv], lenght);
			/*printf("%s ", cpypath);*/
		
			strtok (cpypath, "=:\n");

			while (result != NULL)
			{
				result = strtok(NULL, "=:\n");
				/*printf("%s\n", result);*/
			
				concat = str_concat(result, "/");
				/*printf("%s\n", concat);*/
				concat = str_concat(concat, p[0]);
				/*printf("%s\n", concat);*/

				if (access(concat, F_OK) == 0)
				{
					/*printf("estamos aqui/n");*/
					break;
				}
			}

		}
		if (fork() == 0)
		{
			if (execve(concat, p, NULL) == -1)
			{		
				perror("./shell");
				exit(-1);
			}	
		}

		wait(NULL);
	}
	return(0);
}
