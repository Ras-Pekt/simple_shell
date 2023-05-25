#include "shell.h"

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
	char *home = _getenv("HOME");
	char *oldpwd = _getenv("OLDPWD");
	char *new_wd = NULL;

	if (home == NULL)
	{
		home = "/";
	}

	if (tokenArray[1] == NULL)
	{
		if (chdir(home) != 0)
			perror("cd");
		setenv("OLDPWD", nxtOldPwd, 1);
		setenv("PWD", getcwd(path, 128), 1);
	}
	else if (str_cmp(tokenArray[1], "-") == 0)
	{
		if (oldpwd == NULL)
		{
			oldpwd = "/";
		}

		else if (chdir(oldpwd) != 0)
			perror("cd");

		setenv("OLDPWD", nxtOldPwd, 1);
		setenv("PWD", getcwd(path, 128), 1);

		new_wd = getcwd(path, 128);
		_puts(new_wd);
	}
}
/**
* _puterror - writes a string to stderr
* @str: The string to print
* Return: number of elements printed
*/
int _puterror(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		;

	write(STDERR_FILENO, str, i);

	return (i);
}

