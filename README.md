# SIMPLE SHELL
##### Creating a linux shell with C language.

The shell is a program that provdides and interface which linux users may use to communicate with the Linux Kernel to perform operations.

## Usage

1. clone repo </br>
```
git clone https://github.com/Wa2hingt0n/simple_shell.git
```
2. Enter into the directory **simple_shell**

3. Compile the source file </br>
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
4. Execute the shell </br>
```bash
./hsh 
```
Now you can interact with the linux kernel, most operations that can be done on the bash shell can be done on the shell.

## System calls and functions utilized

* `access (man 2 access)`
* `chdir (man 2 chdir)`
* `close (man 2 close)`
* `closedir (man 3 closedir)`
* `execve (man 2 execve)`
* `exit (man 3 exit)`
* `_exit (man 2 _exit)`
* `fflush (man 3 fflush)`
* `fork (man 2 fork)`
* `free (man 3 free)`
* `getcwd (man 3 getcwd)`
* `getline (man 3 getline)`
* `getpid (man 2 getpid)`
* `isatty (man 3 isatty)`
* `kill (man 2 kill)`
* `malloc (man 3 malloc)`
* `open (man 2 open)`
* `opendir (man 3 opendir)`
* `perror (man 3 perror)`
* `read (man 2 read)`
* `readdir (man 3 readdir)`
* `signal (man 2 signal)`
* `stat (__xstat) (man 2 stat)`
* `lstat (__lxstat) (man 2 lstat)`
* `fstat (__fxstat) (man 2 fstat)`
* `strtok (man 3 strtok)`
* `wait (man 2 wait)`
* `waitpid (man 2 waitpid)`
* `wait3 (man 2 wait3)`
* `wait4 (man 2 wait4)`
* `write (man 2 write)`


### Contributors
* [Joseph Emmanuel](https://github.com/dnjoe96)
* [Washington Obungu](https://github.com/Wa2hingt0n)

If you find some observations or ways to improve this project, kindly reach out to any of us.