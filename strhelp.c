#include "shell.h"

/**
* str_cmp - compare string values
* @s1: string 1
* @s2: string 2
*
* Return: s1[i] - s2[i]
*/
int str_cmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] == s2[i]) && (s1[i] != '\0'))
		i++;

	return (s1[i] - s2[i]);
}

/**
* str_dup - returns a pointer to a newly allocated
*space in memory, which contains a copy of the
*string given as a parameter.
*@str:String to be copied
*
* Return: NULL in case of error, pointer to allocated space.
*/
char *str_dup(const char *str)
{
	char *cpy;
	int index, len;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len]; len++)
		;

	cpy = malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);

	for (index = 0; index < len; index++)
		cpy[index] = str[index];

	cpy[len] = '\0';

	return (cpy);
}
/**
*str_cat - function that concatenates two strings.
*@dest: pointer to destination string.
*@src: pointer to source string.
*
*Return: pointer to destination string.
*/
char *str_cat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}
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
