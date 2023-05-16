#include "shell.h"

/**
 * _getenv - iterates through the environ global variable
 *	to locate a specific variable
 * @name: name of the global variable being searched for.
 *	it is passed in uppercase
 *	global variables are typical declared in uppercase)
 * Return: the value of the specified environ global variable.
 *	EXIT_FAILURE with appropriate error message otherwise
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *token, *result;
	char *dupEnv;

	while (environ[i])
	{
		dupEnv = str_dup(environ[i]);
		token = strtok(dupEnv, "=");
		if (strcmp(token, name) == 0)
		{
			result = str_dup(strtok(NULL, "="));
			free(dupEnv);
			return (result);
		}
		free(dupEnv);
		i++;
	}

	return (NULL);
}
/**
 * _path - creates a linked list using the add_node function
 *	where each node represents a directory path
 *	extracted from the PATH environment variable
 *	The function takes no argument as the "PATH" varianble is hard coded
 * Return: the function returns a head pointer
 *	that points to the first node in the linked list
 */
list_t *_path(void)
{
	char *str, *token;
	list_t *head = NULL;

	str = _getenv("PATH");

	token = strtok(str, ":");
	while (token)
	{
		add_node(&head, token);
		token = strtok(NULL, ":");
	}

	/* free str (from _getenv()) */
	free(str);
	return (head);
}
/**
 * _getpath - gets the path associated with the command shortform
 *	input by the user
 * @str: command shortform input by the user (e.g. ls)
 * Return: the full path to the command shortform (e.g. /bin/ls)
 */
char *_getpath(char *str)
{
	list_t *line = _path();
	char *file_path, *copy;

	while (line)
	{
		file_path = str_cat(line->str, str);

		if (access(file_path, X_OK) == 0)
		{
			copy = str_dup(file_path);
			free_list(line);
			return (copy);
		}

		line = line->next;
	}

	free_list(line);
	return (NULL);
}
/**
 * add_node - adds a new node at the beginning of a list
 * @head: first node
 * @str: input string
 * Return: address of new node
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *newNode;

	if (str == NULL)
		return (NULL);

	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
		return (NULL);

	newNode->str = str_cat(str_dup(str), "/");
	newNode->next = *head;
	*head = newNode;

	return (*head);
}
/**
 * free_list - frees a list
 * @head: first node
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
	head = NULL;
}
