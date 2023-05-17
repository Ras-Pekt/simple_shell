# C - Simple Shell
This is a collaborative project in the ALXSE program to build a simple shell in C to execute simple commands such as ls, pwd, df, man, which etc.

## To Compile the program use:
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o vsh

## Used Functions:
	-isatty()
	-getline()
	-write()
	-strtok()
	-fork()
	-execve()
	-wait()
	-exit()
	-free()
	-malloc()

## Testing:

*Interactive mode:*

'$ ./vsh'
'($) /bin/ls'
'vsh main.c shell.c'
'($)'
'($) exit'
'$'

*non-interactive mode:*

$' echo "/bin/ls" | ./vsh'
'vsh main.c shell.c test_ls_2'
$
$ 'cat test_ls_2'
'/bin/ls'
'/bin/ls'
$
$ 'cat test_ls_2 | ./vsh'
'vsh main.c shell.c test_ls_2'
'vsh main.c shell.c test_ls_2'
$
