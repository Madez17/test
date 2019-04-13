#include <simple_shell.h>

/**
*
*
*
*/

void handle_sigint(int sig) 
{ 
    printf("Caught signal %d\n", sig); 
}
