#include "shell.h"

/**
* depart - tests for builtin commands
* @cmd: command line
* @ln: var for line of str
*/

void depart(char **cmd, char *ln)
{
	if (str_cmp(cmd[0], "exit") == 0)
	{
		free(ln);
		if (cmd[1])
		{
			exit(atoi_(cmd[1]));
		}
		clear_array(cmd);
		exit(0);
	}
}
