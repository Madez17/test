#include "simple_shell.h"

/**
*
* assign_args -
*
*/

char **assign_args(char **p, int cont)
{
       int iter2 = 1;

       while (iter2 < cont)
       {
               p[iter2] = strtok(NULL, " \n");
               iter2++;
       }

       return (p);
}
