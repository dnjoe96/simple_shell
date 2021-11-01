# SIMPLE SHELL
##### Creating a linux shell with C language.

The shell is a program that provdides and interface which linux users may use to communicate with the Linux Kernel to perform operations. 

This is a simple shell closely adopting as many features as possible from the bash shell.

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

## Examples
### Interactive mode
```bash
[vagrant@centos simple_shell]$ ./hsh
$ 

$ pwd
/home/vagrant/simple_shell
$ ls
README.md   built-in.c   fork_exec.c  run.sh  shell.c  string_functions.c
_execute.c  exec_func.c  getpath.c    shell   shell.h  string_tokenizing.c
$
$
$ cd /
$ pwd
/
$ ls
bin  boot  dev  etc  home  lib  lib64  lost+found  media  mnt  opt  proc  root  sbin  selinux  srv  sys  tmp  usr  var
$ cd /root   
lsh: Permission denied
$
$ cd /home
$ pwd
/home
$ cd vagrant
$ pwd
/home/vagrant
$ 
$ help
Joseph & Washington shell
Type program names and arguments, and hit enter.
The following are built in:
* cd
* help
* exit

Use the man command for information on other programs.
$
$ env
HOSTNAME=centos
SELINUX_ROLE_REQUESTED=
TERM=xterm-256color
SHELL=/bin/bash
HISTSIZE=100000
SSH_CLIENT=10.0.2.2 33246 22
SELINUX_USE_CURRENT_RANGE=
SSH_TTY=/dev/pts/0
USER=vagrant
LS_COLORS= [...]
MAIL=/var/spool/mail/vagrant
PATH
PWD=/home/vagrant/simple_shell
LANG=en_US.UTF-8
SELINUX_LEVEL_REQUESTED=
HISTCONTROL=ignoredups
SHLVL=1
HOME=/home/vagrant
LOGNAME=vagrant
SSH_CONNECTION=10.0.2.2 33246 10.0.2.15 22
LESSOPEN=||/usr/bin/lesspipe.sh %s
G_BROKEN_FILENAMES=1
_=./shell
OLDPWD=/home/vagrant
$ 
$ exit
[vagrant@centos simple_shell]$ 

```
### Non-interactive mode

```bash
[vagrant@centos simple_shell]$ echo "ls -lah" | ./hsh
total 76K
drwxr-xr-x. 3 vagrant vagrant 4.0K Nov  1 13:45 .
drwx------. 5 vagrant vagrant 4.0K Nov  1 13:44 ..
drwxrwxr-x. 8 vagrant vagrant 4.0K Nov  1 13:45 .git
-rw-rw-r--. 1 vagrant vagrant    9 Nov  1 13:45 .gitignore
-rw-rw-r--. 1 vagrant vagrant 1.7K Nov  1 13:45 README.md
-rw-rw-r--. 1 vagrant vagrant  381 Nov  1 13:45 _execute.c
-rw-rw-r--. 1 vagrant vagrant 1.5K Nov  1 13:45 built-in.c
-rw-rw-r--. 1 vagrant vagrant 1.2K Nov  1 13:45 exec_func.c
-rw-rw-r--. 1 vagrant vagrant  478 Nov  1 13:45 fork_exec.c
-rw-rw-r--. 1 vagrant vagrant 1.1K Nov  1 13:45 getpath.c
-rwxrwxr-x. 1 vagrant vagrant   83 Nov  1 13:45 run.sh
-rwxrwxr-x. 1 vagrant vagrant  13K Nov  1 13:45 shell
-rw-rw-r--. 1 vagrant vagrant 1.3K Nov  1 13:45 shell.c
-rw-rw-r--. 1 vagrant vagrant 1.2K Nov  1 13:45 shell.h
-rw-rw-r--. 1 vagrant vagrant 1.1K Nov  1 13:45 string_functions.c
-rw-rw-r--. 1 vagrant vagrant  560 Nov  1 13:45 string_tokenizing.c
[vagrant@centos simple_shell]$ 
[vagrant@centos simple_shell]$ echo "hostname" | ./hsh
centos
[vagrant@centos simple_shell]$
[vagrant@centos simple_shell]$ echo "date" | ./shell
Mon Nov  1 14:07:21 PDT 2021
[vagrant@centos simple_shell]$
```
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