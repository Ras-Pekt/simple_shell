#include "shell.h"

/**
* _read - reads input from the user
*
* Return: user input. NULL otherwise
*/
char *_read()
{
	char *line = NULL;
	size_t n = 0;

	if (getline(&line, &n, stdin) == -1)
	{
		free(line);
		return (NULL); /* end of file */
	}
	return (line);
}
/**
* splitString - splits string and stores into array
* @str: input string from user
* @tokenArray: array to store split string
* @max: maximum size of array
* Return: number of tokens
*/
int splitString(char *str, char **tokenArray, int max)
{
	int i = 0;
	char *token;

	token = strtok(str, " \n");
	while (token != NULL && i < max)
	{
		if (str_cmp(token, "#") == 0)
		{
			break;
		}
		tokenArray[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	tokenArray[i] = NULL;
	return (i);
}
/**
* _execute - executes execve by forking parent process
* @tokenArray: array of tokens
* @count: count of processes
* @av: argument vector
* Return: void
*/

void _execute(char **tokenArray, int count, char *av)
{
	pid_t pid;
	int status;
	char *error = av;
	char *path = _check_executable(tokenArray);

	if (path == NULL)
	{
		_perror(error, count, tokenArray);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, tokenArray, environ) == -1)
		{
			perror("execve failure");
			return;
		}
	}
	else if (pid > 0)
	{
		if (wait(&status) == -1)
		{
			perror("wait failed");
			return;
		}

	}
	else
		perror("fork failed");
}
/**
 * _check_executable - checks if user's input is an executable file
 * @tokenArray: array of user's input
 * Return: path. NULL otherwise
 */
char *_check_executable(char **tokenArray)
{
	char *path;

	if (access(tokenArray[0], X_OK) == 0)
	{
		path = tokenArray[0];
		return (path);
	}
	else
	{
		path = _getpath(tokenArray[0]);

		if (path == NULL)
			return (NULL);
		else
			return (path);
	}
}
