#include "simple_shell.h"

/**
* _strcmp - concatenacion.
*
* @s1: dest array
* @s2: array
* @n: limit char
*
* Return: Always 0.
*/
int _strcmp(char *s1, char *s2, int n)
{
	int result;
	int cont;

	for (cont = 0; s1[cont] != '\0' && cont < n; cont++)
	{
		result = s1[cont] - s2[cont];

		/*printf("%d\n", result);*/
		if (result != 0)
		{
			/*printf("Estamos aqui");*/
			return (1);
		}
	}
	return (0);
}
