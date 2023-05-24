#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

void _path(char **cmd);
ssize_t str_len(char *s);
int str_cmp(char *st1, char *st2);
char *str_cpy(char *destn, char *src);
char *app_string(char *destn, const char *src);
void depart(char **cmd, char *ln);
int str_cmp2(const char *st1, const char *st2);
int atoi_(char *s);
void envr(void);
int put_char(char c);
void snal_H(__attribute__((unused)) int s_num);
int str_len2(char *s);
void clear_array(char **array);
void put_char2(char *c);
void lup(int inpt);
void ex_cd(char **cmd);
void *rea_lloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *str_dup(char *str);
char **str_splt(char *ln, char *delim);
char *strn_cpy(char *dest, const char *src, size_t n);
ssize_t my_puts(char *s);


#endif
