#include "shell.h"

/**
 * _atoi - converts string into integers
 * @str: input string
 * Return: converted string to integer
 */
int _atoi(char *str)
{
	int sign = 1, convNum = 0;

	for (; *str; str++)
	{
		if (*str == '-')
			sign *= -1;
		else if (*str >= '0' && *str <= '9')
			convNum = (*str - '0') + (convNum * 10);
		else if (convNum > 0)
			break;
	}
	return (convNum * sign);
}
/**
 * str_cpy - copies one string to another
 * @dest: input variable
 * @src: input variable
 * Return: returns char
 */
char *str_cpy(char *dest, char *src)
{
	int i = 0;
	int j;

	while (src[i] != '\0')
	{
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		*(dest + j) = *(src + j);
	}
	dest[j] = '\0';
	return (dest);
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
/**
* _perror - prints error of commands not found
* @av: name of the shell
* @count: shell iteration count
* @tokenArray: array containing user tokenized string
* Return: nothing
*/
void _perror(char *av, int count, char **tokenArray)
{
	_puts(av);
	_puts(": ");
	_putint(count);
	_puts(": ");
	_puts(tokenArray[0]);
	_puts(": not found\n");
}


