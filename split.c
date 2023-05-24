#include "shell.h"

/**
 * str_splt - funtion
 * @ln: var
 * @delim: var
 * Return: array of elements
 */

char **str_splt(char *ln, char *delim)
{
	char *ptr = NULL, **cmd = NULL;
	size_t i = 0, old = 0;

	ptr = strtok(ln, delim);
	while (ptr)
	{
		cmd = rea_lloc(cmd, old, ((i + 1) * sizeof(char *)));
		cmd[i] = str_dup(ptr);
		ptr = strtok(NULL, delim);
		i++;
		old = i * sizeof(char *);
	}
	cmd = rea_lloc(cmd, old, ((i + 1) * sizeof(char *)));
	cmd[i] = NULL;
	return (cmd);
}
