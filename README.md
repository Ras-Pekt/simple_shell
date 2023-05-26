# C - Simple Shell
This is a collaborative project in the ALXSE program to build a simple shell in C to execute simple commands such as ls, pwd, df, man, which etc.


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


## Requirements

* gcc (GNU Compiler)

## How to use
1. Clone the repository to your local machine

```
$ git clone https://github.com/Ras-Pekt/simple_shell.git
```

2. Open the terminal and navigate to the project directory

```
$ cd simple_shell
```

3. Compile the shell script

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o vsh
```

4. Run the shell script

```
./vsh
```

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

## Contributors

**Authors:** *Gituku and Lavender*
