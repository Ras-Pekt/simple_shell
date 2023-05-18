# C - Simple Shell
This is a collaborative project in the ALXSE program to build a simple shell in C to execute simple commands such as ls, pwd, df, man, which etc.

## Installation
Clone this repositiory. Once the files are in the local working directory, compile the code with gcc with the following flags:

`
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o vsh
`

To run the shell, simply run the command:
	```
	./vsh
	```

## Functions Used:
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

## Usage
The shell is designed to work in both interactive
```
	$ ./vsh
	my_sh$ ls
	main.c	mysh  shell.c  test_ls_2
	my_sh$ exit
	$
```
and non-interactive mode
```
	$ cat test_ls_2
	/bin/ls
	/bin/ls
	$ cat test_ls_2 | ./vsh
	main.c	mysh  shell.c  test_ls_2
	main.c	mysh  shell.c  test_ls_2
	$
```

