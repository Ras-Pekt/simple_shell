#include "shell.h"

/**
 * ex_cd - function
 * @cmd: command line
 */

void ex_cd(char **cmd)
{
	pid_t bd = 0;
	int i = 0;

	if (cmd)
	{
		bd = fork();
		if (bd == -1)
		{
			perror("Error in fork");
			exit(EXIT_FAILURE);
		}
		else if (bd == 0)
		{
			if (execve(cmd[0], cmd, environ) == -1)
			{
				perror(cmd[0]);
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			waitpid(bd, &i, 0);
		}
	}
}
