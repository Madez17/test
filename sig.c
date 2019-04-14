#include "simple_shell.h"

/**
* handle_sigint - Function
*
* @sig: signal parameter
*/

void handle_sigint(int sig)
{
	(void) sig;
	write(1, "\n#cisfun$ ", 11);
	fflush(stdout);
}
