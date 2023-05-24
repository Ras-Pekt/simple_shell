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
		return (NULL);
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

	while (token && i < max)
	{
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
 * @env: environ array
 * Return: void
 */
int _execute(char **tokenArray, int count, char *av, char **env)
{
	pid_t pid;
	int status;
	char *error = av;
	char *path = _getpath(tokenArray[0]);

	if (access(tokenArray[0], X_OK) != 0 && path == NULL)
	{
		_perror(error, count, tokenArray);
		return (-1);
	}

	pid = fork();
	
	if (pid == 0)
	{
		if (access(tokenArray[0], X_OK) == 0)
			execve(tokenArray[0], tokenArray, env);
		else
			execve(path, tokenArray, env);
	}
	else if (pid > 0)
	{
		if (wait(&status) == -1)
		{
			perror("Wait failed");
			return (-1);
		}
	}
	else
		perror("Folk failed");

	free(path);
	return (0);
}
/**
* _env - prints the current environment
* @env: environment array
* Return: No. of env variables printed
*/
int _env(char **env)
{
	int i = 0;

	while (env[i])
	{
		_puts(env[i]);
		_puts("\n");
		i++;
	}
	return (i);
}
/**
* _argExit - handles arguments for builtin exit
* @av: name of the shell
* @count: count of process iterations
* @str: malloc'ed strings
* @tokenArray: array of user input
* Return: void
*/
void _argExit(char *av, int count, char *str, char **tokenArray)
{
	if (tokenArray[1] != NULL)
	{
		int i = _atoi(tokenArray[1]);

		if (i < 0)
		{
			_puts(av), _puts(": "), _putint(count);
			_puts(": exit: Illegal number: ");
			_puts(tokenArray[1]);
			_puts("\n");
			return;
		}
		else
		{
			free(str);
			exit(i);
		}
	}
	else
	{
		free(str);
		exit(EXIT_SUCCESS);
	}
}
