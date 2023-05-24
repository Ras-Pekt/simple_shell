#include "shell.h"

/**
 * snal_H - handles Control-C signal
 * @s_num: var
 */

void snal_H(__attribute__((unused)) int s_num)
{
	signal(SIGINT, snal_H);
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$ ", 2);
}
