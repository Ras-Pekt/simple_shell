#include "shell.h"

/**
 * _path - gets the path
 * @cmd: the command line
 */

void _path(char **cmd)
{
	int i;
	int len = 0;
	char **token = NULL, *path = NULL, *tmp = NULL, *env = environ[0];

	while (env[len] != '=')
	{
		len++;
	}
	path = malloc(sizeof(char) * (str_len(env + len + 1) + 1));
	str_cpy(path, env + len + 1);
	token = str_splt(path, ":");
	free(path);
	for (i = 0; token[i]; i++)
	{
		tmp = malloc((str_len(token[i] + str_len(cmd[0]) + 2) * sizeof(char)));
		str_cpy(tmp, token[i]);
		app_string(tmp, "/");
		app_string(tmp, cmd[0]);
		if (access(tmp, F_OK) == 0)
			break;
		free(tmp);
		tmp = NULL;
	}
	clear_array(token);
	if (tmp != NULL && (str_cmp(cmd[0], "ls") == 0 || str_cmp(cmd[0], "echo")
				== 0 || str_cmp(cmd[0], "rm") == 0))
	{
		free(cmd[0]);
		cmd[0] = tmp;
		return;
	}
	if (tmp != NULL)
		free(tmp);
	free(cmd[0]);
	cmd[0] = NULL;
}
