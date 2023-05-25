#include "shell.h"

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
/**
* _setenv - implements setenv builtin command
* @tokenArray: array of user input
* Return: void
*/
void _setenv(char **tokenArray)
{
	int n;

	if (tokenArray[1] == NULL || tokenArray[2] == NULL || tokenArray[3] == NULL)
	{
		_puterror("Usage: setenv <name> <value> <overwrite>\n");
		return;
	}
	n = _atoi(tokenArray[3]);
	if (setenv(tokenArray[1], tokenArray[2], n) == -1)
		_puterror("setenv: failed to set environment variable\n");
}
/**
* _unsetenv - implements unsetenv builtin command
* @tokenArray: array of user input
* Return: void
*/
void _unsetenv(char **tokenArray)
{
	if (tokenArray[1] == NULL)
		_puterror("Usage: unsetenv <name>\n");
	else if (unsetenv(tokenArray[1]) == -1)
		_puterror("unsetenv: failed to unset environment variable\n");
}
/**
* _chdir - implements cd builtin command
* @tokenArray: array of user input
* Return: void
*/
void _chdir(char **tokenArray)
{
	char path[128];
	/*the current pwd is the nxtOldPwd*/
	char *nxtOldPwd = getcwd(path, 128);

	if (tokenArray[1] == NULL)
	{
		if (chdir(_getenv("HOME")) != 0)
			perror("cd");
		setenv("OLDPWD", nxtOldPwd, 1);
		setenv("PWD", getcwd(path, 128), 1);
	}
	else if (str_cmp(tokenArray[1], "-") == 0)
	{
		if (_getenv("OLDPWD") == NULL)
			_puterror("./mysh: cd: OLDPWD not set\n");
		if (chdir(_getenv("OLDPWD")) != 0)
			perror("cd");
		setenv("OLDPWD", nxtOldPwd, 1);
		setenv("PWD", getcwd(path, 128), 1);
	}
	else
	{
		if (chdir(tokenArray[1]) != 0)
			perror("cd");
		setenv("OLDPWD", nxtOldPwd, 1);
		setenv("PWD", getcwd(path, 128), 1);
	}
}
