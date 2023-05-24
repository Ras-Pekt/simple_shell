#include "shell.h"

/**
 * envr - prints the environment
 */

void envr(void)
{
	char **e = environ;

	for (; *e; e++)
		my_puts(*e), my_puts("\n");
}
