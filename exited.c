#include "simple_shell.h"

int _exited(char *comm)
{
       if((_strlen(comm) - 4) >= 0)
       {
               if (_strcmp(comm, "exit", 4) == 0)
               {
                       return(0);
               }
       }
       return(1);
}
