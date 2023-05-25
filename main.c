#include "shell.h"
/**
* main - Entry point
* @ac: argument count
* @av: argument vector
* @env: environ array
* Return: 0 on success
*/
int main(int ac, char **av, char **env)
{
	char *str = NULL;
	char *argv[1024];
	int tok_return;
	static int count = 1;

	(void)ac;

	while (1)
	{
		int *ptr_count = &count;

		prompt();
		str = _read();
		ctrl_d(str);
		tok_return = splitString(str, argv, 1024);
		if  (tok_return > 0)
		{
			if (str_cmp(argv[0], "exit") == 0)
				_argExit(av[0], count, str, argv);
			else if (str_cmp(argv[0], "env") == 0)
				_env(env);
			else if (str_cmp(argv[0], "setenv") == 0)
				_setenv(argv);
			else if (str_cmp(argv[0], "unsetenv") == 0)
				_unsetenv(argv);
			else if (str_cmp(argv[0], "cd") == 0)
				_chdir(argv);
			else
				_execute(argv, count, av[0]);
		}
		free(str);
		*ptr_count = count + 1;
	}

	return (0);
}
/**
* _puts - writes a string to stdout
* @str: The string to print
* Return: number of elements printed
*/
int _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	write(STDOUT_FILENO, str, i);

	return (i);
}
/**
* _putint - prints any integer using _puts
* @n: input integer
* Return: nothing
*/
void _putint(int n)
{
	char temp, str[10];
	int len = 0, i = 0, digit, j;

	while (n > 0)
	{
		digit = n % 10;
		str[len] = digit + '0';
		n /= 10;
		len++;
	}
	str[len] = '\0';

	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	_puts(str);
}

/**
* prompt - displays the prompt
* Return: nothing
*/
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "vsh$ ", 5);
}
/**
 * ctrl_d - checks for EOF
 * @str: input string
 * Return: nothing
 */
void ctrl_d(char *str)
{
	if (str == NULL)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(str);
		exit(EXIT_SUCCESS);
	}
}
