#include "simple_shell.h"

/**
 *
 * main - Function
 *
 */

int main(int argc, char *argv[])
{
	extern char **environ;
	char *buffer, *cpyenv, *cpypath, *result, *concat, *concat_slash, **p;
	//size_t sizebuf = 0;
	//ssize_t characters;
	int iter, cont, iter2, iterenv, lenght, own_comm, alone_comm, basura;

	pid_t my_pid;
	pid_t my_ppid;
	
    	my_pid = getpid();
	my_ppid = getppid();

	buffer = NULL;
	/*buffer = malloc(sizeof(char *) * 1024);
	if (!buffer)
		return (0);*/

	while (1)
	{
		/*SETEO VARIABLES -------------------*/
		own_comm = 1;
		result = "";
		/*BUFFER -----------------------------_getline()*/
		/*write(1, "#cisfun$ ", 9);
		
		characters = getline(&buffer, &sizebuf, stdin);
		if (characters == EOF)
		{
			perror("./shell");
			free(buffer);
			exit(-1);
		}*/
		buffer = _prompt(buffer);

		iter = 0;
		cont = 0;

		/*BUFFER ITERATE ------------------------ _store_args*/
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
		if(p == NULL)
		{
			/*free(buffer);*/
			return (0);
		}
		
		/*SEPARATOR ---------------------------Asignacion Primer argumento*/
		p[0] = strtok(buffer, " \n");
		if (p[0] != NULL)
		{	
			/*printf("%p\n", p[0]);*/

			/* 1-OWNER FUNCTIONS ------------------------------------*/
			/*exit*/
			if((_strlen(p[0]) - 4) >= 0)
			{
				if (_strcmp(p[0], "exit", 4) == 0)
				{
					free(buffer);
					free(p);
					exit(-1);
				}
			}
			/*env*/
			if((_strlen(p[0]) - 3) >= 0)
			{
				if (_strcmp(p[0], "env", 3) == 0)
				{
					for (iterenv = 0; environ[iterenv] != NULL; iterenv++)
					{	
						lenght = _strlen(environ[iterenv]);
						/*printf("%s", environ[iterenv]);
						printf("%d", lenght);*/
						write(1, environ[iterenv], lenght);
						write(1, "\n", 1);
					}
					own_comm = 0;
				}
			}

			/*----------------------------------------------------------------*/

			/*printf("%s ", p[0]);*/

			/* 2-SYSTEM FUNCTIONS ---------------------*/
			if(own_comm == 1)
			{
				alone_comm = 1;
				/*printf("ls esta aqui\n");*/

				/*ASSIGN PARAMETERS -------------------------------------*/
				iter2 = 1;
				while (iter2 < cont)
				{
					p[iter2] = strtok(NULL, " \n");
					/*printf("%s ", p[iter2]);*/
					iter2++;
				}

				concat = p[0];
				/*printf("Comando: %s\n", concat);*/

				/* 2.2- OPCION ACCESO ONLY COMMAND: ls -----------------*/
				if (access(p[0], F_OK) != 0)
				{
					alone_comm = 0;
					basura = 0;
					/*printf("el comando no es una direccion\n");*/
					
					/*FOUND PATH -------------------------------------------*/
					for (iterenv = 0; environ[iterenv] != NULL; iterenv++)
					{
						if (_strcmp(environ[iterenv], "PATH=", 5) == 0)
						{
							/*printf("%s ", environ[iterenv]);*/
							break;
						}
					}

					lenght = _strlen(environ[iterenv]);
					/*printf("%d\n", lenght);*/
					
					cpyenv = malloc(sizeof(char) * lenght + 1);
					if (cpyenv == NULL)
					{
						free(buffer);
						free(p);
						return (0);
					}
					cpypath = _strncpy(cpyenv, environ[iterenv], lenght);
					/*printf("%s ", cpypath);*/
					/*CUT PATH -----------------------------------------EXECUTE_OK*/	
					strtok (cpypath, "=:\n");

					while (result != NULL)
					{
						result = strtok(NULL, "=:\n");
						/*printf("Directorio = %s\n", result);*/
					
						concat_slash = str_concat(result, "/");
						/*printf("Directorio + / = %s\n", concat);*/
						concat = str_concat(concat_slash, p[0]);
						/*printf("Comando concatenado = %s\n", concat);*/

						if (access(concat, F_OK) == 0)
						{
							free(concat_slash);
							basura = 1;
							/*printf("estamos aqui/n");*/
							break;
						}
						free(concat_slash);
						free(concat);
					}
				}
				/*printf("Comando final: %s\n", concat);*/
				if (fork() == 0)
				{
					if (execve(concat, p, NULL) == -1)
					{	
						free(p);
						free(buffer);
						free(cpyenv);
						/*free(concat);*/
						perror("./shell");
						exit(-1);
					}
					/*free(p);*/
					/*free(buffer);*/
					/*free(cpyenv);*/
					/*free(concat);*/

				}
				else
				{
					/*free(p);*/
					/*free(buffer);*/
					if(alone_comm == 0)
					{
						free(cpyenv);
						free(concat);
					}
					if(alone_comm == 0 && basura != 0)
					{
						free(p);
					}


				}
				wait(NULL);
			}
			else
			{
				free(p);
			}
		}
		else
		{
			free(p);
		}
	}
	return(0);
}
