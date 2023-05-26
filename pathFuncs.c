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
	int i = 0, var_len;
	char *result;

	var_len = str_len(name);

	while (environ[i])
	{
		if (strn_cmp(name, environ[i], var_len) == 0 && environ[i][var_len] == '=')
		{
			result = &environ[i][var_len + 1];
			return (result);
		}
		i++;
	}

	return (NULL);
}
/**
* _path - creates a linked list where each node represents a directory path
*	extracted from the PATH environment variable
*	The function takes no argument as the "PATH" varianble is hard coded
* Return: the function returns a head pointer
*	that points to the first node in the linked list
*/
list_t *_path(void)
{
	char *str, *token, *dupStr;
	list_t *head = NULL, *newNode;

	str = _getenv("PATH");

	if (str == NULL)
		return (NULL);

	dupStr = str_dup(str);

	token = strtok(dupStr, ":");
	while (token)
	{
		newNode = malloc(sizeof(list_t));
		if (newNode == NULL)
		{
			free_list(head);
			free(dupStr);
			return (NULL);
		}
		newNode->str = str_dup(token);
		newNode->next = head;
		head = newNode;

		token = strtok(NULL, ":");
	}

	free(dupStr);
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
	char *cmd_path = NULL, *dupPath = NULL, *new_path;
	int lenStr, lenDupPath, mallocLen;
	list_t *line = _path();

	lenStr = str_len(str);

	while (line != NULL)
	{
		dupPath = line->str;
		lenDupPath = str_len(dupPath);
		mallocLen = lenDupPath + lenStr;
		new_path = malloc((mallocLen + 2) * sizeof(char));

		if (new_path == NULL)
			return (NULL);

		str_cpy(new_path, dupPath);
		str_cat(new_path, "/");
		str_cat(new_path, str);
		if (access(new_path, X_OK) == 0)
		{
			cmd_path = new_path;
			break;
		}
		free(new_path);
		line = line->next;
	}
	return (cmd_path);
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

