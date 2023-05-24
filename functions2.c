#include "shell.h"

/**
 * atoi_ - converts a string to an integer
 * @s: string to be converted
 * Return: int value of s
 */

int atoi_(char *s)
{
	int result = 0;
	int sgn = 1;
	int i = 0;

	if (s[0] == '=')
	{
		sgn = -1;
		i++;
	}
	for (; s[i] != '\0'; ++i)
	{
		if (s[i] < '0' || s[i] > '9')
			break;
		result = result * 10 + s[i] - '0';
	}
	return (sgn * result);
}
