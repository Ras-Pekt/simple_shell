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
 * Return: number of tokens
 */
int splitString(char *str, char **tokenArray)
{
	int i = 0;
	char *token;

	token = strtok(str, " \n");

	while (token)
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
 * @av: argument vector
 * @env: environ array
 * Return: void
 */
int _execute(char **tokenArray, char *av, char **env)
{
	pid_t pid;
	int status;
	char *error = av;
	char *path = _getpath(tokenArray[0]);

	if (access(tokenArray[0], X_OK) != 0 && path == NULL)
	{
		write(STDIN_FILENO, error, str_len(error));
		perror(" ");
		return (-1);
	}

	pid = fork();
	if (pid == -1)
		perror("Folk failed");

	if (pid == 0)
	{
		if (access(tokenArray[0], X_OK) == 0)
			execve(tokenArray[0], tokenArray, env);
		else
			execve(path, tokenArray, env);
	}
	else
		wait(&status);

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
	int i = 0, len = 0;

	while (env[i])
	{
		len = str_len(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (i);
}
/**
 * _argExit - handles arguments for builtin exit
 * @tokenArray: array of user input
 * Return: void
 */
void _argExit(char **tokenArray)
{
	if (tokenArray[1] != NULL)
		exit(atoi(tokenArray[1]));
	else
		exit(EXIT_SUCCESS);
}


