#include "shell.h"

/**
 * str_len - computes lenght of a string
 * @s: string pointer
 * Return: length of string
 */

ssize_t str_len(char *s)
{
	ssize_t len = 0;

	while (s && *(s + len))
	{
		len++;
	}
	return (len);
}

/**
 * str_cmp - compares two strings
 * @st1: pointer to string 1
 * @st2: pointer to string 2
 * Return: 0 if strings are equal, negative value if st1 < st2
 * or positive value if st1 > st2
 */

int str_cmp(char *st1, char *st2)
{
	int i = 0;

	while (st1[i] == st2[i])
	{
		if (st1[i] == '\0')
			return (0);
		i++;
	}
	return (st1[i] - st2[i]);
}

/**
 * str_cpy - copies string
 * @destn: pointer
 * @src: pointer to string
 * Return: pointer to destn
 */

char *str_cpy(char *destn, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		destn[i] = src[i];
	*destn = '\0';
	return (destn);
}

/**
 * app_string - appends a string
 * @destn: pointer
 * @src: pointer to string
 * Return: pointer to destn
 */

char *app_string(char *destn, const char *src)
{
	int destn_len = 0;
	int i = 0;

	while (destn[destn_len] != '\0')
		destn_len++;
	while (src[i] != '\0')
	{
		destn[destn_len] = src[i];
		destn_len++;
		i++;
	}
	destn[destn_len] = '\0';
	return (destn);
}

/**
 * str_cmp2 - compares strings
 * @st1: st1
 * @st2: st2
 * Return: st1 - st2
 */

int str_cmp2(const char *st1, const char *st2)
{
	while (*st1 && (*st1 == *st2))
	{
		st1++;
		st2++;
	}
	return (*(const unsigned char *)st1 - *(const unsigned char *)st2);
}
