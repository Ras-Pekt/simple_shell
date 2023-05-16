#include "shell.h"

/**
 * str_len - Returns the length of a string
 * @s: The string to get the length of
 *
 * Return: The length of @s.
 */

int str_len(char *s)
{
	int i = 0;

	while (*s++)
		i++;

	return (i);
}

/**
 *str_cpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */

char *str_cpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	return (dest);
}


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
	{
		i++;
	}
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
	/*determining length of string given*/
	for (index = 0; str[index]; index++)
		len++;
	cpy = malloc(sizeof(char) * (len + 1));

	if (cpy == NULL)
		return (NULL);
	/* copying @str string into the new string(cpy)*/
	for (index = 0; str[index]; index++)
	{
		cpy[index] = str[index];
	}

	cpy[len] = '\0';

	return (cpy);
}
