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
	char *str;
	int tok_return;
	char *argv[1024];

	(void)ac;
	(void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "vsh$ ", 5);

		str = _read();

		if (str == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(str);
			exit(EXIT_SUCCESS);
		}

		tok_return = splitString(str, argv);

		if (tok_return > 0)
		{
			if (strcmp(argv[0], "exit") == 0)
				_argExit(argv);
			else if (strcmp(argv[0], "env") == 0)
				_env(env);
			else
				_execute(argv, av[0], env);
		}

		free(str);
	}

	return (0);
}
