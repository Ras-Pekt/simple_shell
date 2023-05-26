#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

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

void _putint(int n);
int _puts(char *str);
void _perror(char *av, int count, char **tokenArray);
void prompt(void);
void ctrl_d(char *str);

int str_cmp(char *s1, char *s2);
char *str_dup(const char *str);
char *str_cat(char *dest, char *src);
int str_len(const char *s);
int strn_cmp(const char *s1, const char *s2, size_t num);

char *_check_executable(char **argv);
void _execute(char **tokenArray, int count, char *av);
char *_read();
int splitString(char *str, char **tokenArray, int max);

void free_list(list_t *head);
list_t *_path(void);
char *_getpath(char *str);
char *_getenv(const char *name);

int _atoi(char *str);
char *str_cpy(char *dest, char *src);
int _puterror(char *str);

void _argExit(char *av, int count, char *str, char **tokenArray);
int _env(char **env);
void _setenv(char **tokenArray);
void _unsetenv(char **tokenArray);
void _chdir(char **tokenArray);

void file_reader(int ac, char **av, int count);

#endif
