#include "shell.h"

/**
 * clear_array - free an array
 * @array: array to free
 */

void clear_array(char **array)
{
	int i;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}

/**
 * main - function
 * Return: 0
 */

int main(void)
{
	signal(SIGINT, snal_H);
	lup(isatty(STDIN_FILENO));

	return (0);
}
