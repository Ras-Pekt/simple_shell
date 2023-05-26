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
* space in memory, which contains a copy of the
* string given as a parameter.
* @str:String to be copied
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
 * str_len - calculates length of a string
 * @s: input variable
 * Return: length of string
 */
int str_len(const char *s)
{
	int sum = 0;

	while (*(s + sum) != '\0')
	{
		sum = sum + 1;
	}
	return (sum);
}

/**
 * strn_cmp - compares two strings
 *		checks if they are equal up to the first num characters
 * @s1: string one compared
 * @s2: string compared with string one
 * @num: compares the first num characters of s1 and s2
 * Return: 0 on success
 */
int strn_cmp(const char *s1, const char *s2, size_t num)
{
	size_t i;

	for (i = 0; i < num; i++)
	{
		if ((*s1 == '\0' || *s1 != *s2) && i < num)
			return (*s1 - *s2);

		s1++;
		s2++;
	}
	return (0);
}

