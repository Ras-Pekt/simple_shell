#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/**
* struct list_s - singly linked list
* @str: string - (malloc'ed string)
* @next: points to the next node
*
* Description: singly linked list node structure
*/
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

int _puts(char *str);
void _putint(int n);
void _perror(char *av, int count, char **tokenArray);
void prompt(void);

char *_read();
int splitString(char *str, char **tokenArray,  int max);
int _execute(char **tokenArray, int count, char *av, char **env);
int _env(char **env);
void _argExit(char *av, int count, char *str, char **tokenArray);

char *_getenv(const char *name);
list_t *_path(void);
char *_getpath(char *str);
list_t *add_node(list_t **head, const char *str);
void free_list(list_t *head);

int str_cmp(char *s1, char *s2);
char *str_dup(const char *str);
char *str_cat(char *dest, char *src);
int _atoi(char *str);

void _setenv(char **tokenArray);
void _unsetenv(char **tokenArray);
void _chdir(char **tokenArray);
int _puterror(char *str);

#endif
