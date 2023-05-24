#include "shell.h"

/**
 * str_dup - duplicates a string
 * @str: string
 * Return: pointer to duplicated string or NULL if str is NULL
 */

char *str_dup(char *str)
{
	char *str_new;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	str_new = malloc(sizeof(char) * (len + 1));
	if (str_new == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		str_new[i] = str[i];
	str_new[len] = '\0';
	return (str_new);
}

/**
 * rea_lloc - function
 * @ptr: previous
 * @old_size: old
 * @new_size: new
 * Return: pointer
 */

void *rea_lloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *old_ptr = ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	for (i = 0; i < old_size && i < new_size; i++)
		new_ptr[i] = old_ptr[i];
	free(ptr);
	return (new_ptr);
}

/**
 * strn_cpy - copies a string up to n characters
 * @dest: pointer
 * @src: pointer
 * @n: max number of characters to copy
 * Return: pointer to dest
 */

char *strn_cpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
