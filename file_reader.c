#include "shell.h"

/**
 * file_reader - takes a file as a command line argument
 * @ac: argument count
 * @av: argument vector
 * @count: count of processes
 * Return: 0 on success
 */
void file_reader(int ac, char **av, int count)
{
	char *line = NULL;
	char *argv[1024];
	int tok_return;
	size_t n = 0;
	FILE *fd;
	int *ptr_count = &count;

	if (ac != 2 || access(av[1], F_OK) != 0)
	{
		_puts(av[0]), _puts(": 0: cannot open ");
		_puts(av[1]), _puts(": No such file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		_puts("Error: Cannot open ");
		_puts(av[1]);
		_puts("\n");
		exit(2);
	}

	while (getline(&line, &n, fd) != -1)
	{
		tok_return = splitString(line, argv, 1024);
		if (tok_return > 0)
			_execute(argv, count, av[0]);
		*ptr_count = count + 1;
	}
	free(line);
	fclose(fd);
	exit(EXIT_SUCCESS);
}
