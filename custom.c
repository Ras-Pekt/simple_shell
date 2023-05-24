#include "shell.h"

/**
 * my_puts - function
 * @str: str
 * Return: number
 */

ssize_t my_puts(char *str)
{
	ssize_t len = str_len(str);

	return (write(STDOUT_FILENO, str, len));
}
