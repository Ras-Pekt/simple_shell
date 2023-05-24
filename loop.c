#include "shell.h"

/**
 * lup - loop funtion
 * @inpt: return value of isatty 0 or 1
 */

void lup(int inpt)
{
	char *ln = NULL, **cmd = NULL;
	size_t size = 0;
	int dist;
	struct stat shape;

	while (1)
	{
		if (inpt)
			write(STDOUT_FILENO, "$ ", 2);
		dist = getline(&ln, &size, stdin);
		if (dist == EOF)
		{
			free(ln);
			exit(0);
		}
		if (str_cmp2(ln, "\n") == 0)
			continue;
		cmd = str_splt(ln, "\t\r\n");
		depart(cmd, ln);
		if (str_cmp2(cmd[0], "env") == 0)
		{
			envr();
			clear_array(cmd);
			continue;
		}
		if (stat(cmd[0], &shape) != 0)
			_path(cmd);
		if (cmd[0] == NULL)
		{
			write(STDERR_FILENO, "Command not found\n",  18);
			free(ln);
			ln = NULL;
			clear_array(cmd);
			cmd = NULL;
			continue;
		}
		ex_cd(cmd);
		clear_array(cmd);
	}
	free(ln);
}
