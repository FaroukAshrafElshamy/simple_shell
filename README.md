# Implementation of sh in C programming language

# <a href="url"><img src="https://images.assetsdelivery.com/compings_v2/dmstudio/dmstudio1606/dmstudio160600030.jpg" align="middle" width="100" height="100"></a> simple_shell

<a href="https://alxafrica.com"><img src="https://lh3.googleusercontent.com/oVJxT1yn7vwaEM8t9A5MGL6emG0j-_uqHa5H8ikWLvl6Ka-nVmUJZblqWDqPiY-S6itPLnZNgcc8rviK8AVT65l_a3zHiyctwy8=s0" align="right" width="320" height="200" alt="Alx School" border="0"></a>

## Overview
simple_shell is a project on the UNIX Shell. The UNIX Shell is a command-line interpreter or shell that provides a command-line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language and is used by the operating system to control the execution of the system using shell scripts.…
   ```sh
   access, execve, exit, fork, free, malloc, read, signal, wait, write.
   ```

## Content
* [Installation](#Installation)
* [Compilation](#Compilation)
* [Testing](#Testing)
* [General Requirements](#General-Requirements)
* [Target output](#Target-output)
* [Example of Use](#examples)
* [Tasks](#Tasks)
* [List of allowed functions](#list-of-allowed-functions--syscalls)
* [Authors](#authors)


## List of allowed functions / syscalls
| Functions | Reference |
| --------- | --------- |
| `access` | [man 2 access](https://linux.die.net/man/2/access) |
| `chdir` | [man 2 chdir](https://linux.die.net/man/2/chdir) |
| `close` | [man 2 close](https://linux.die.net/man/2/close) |
| `closedir` | [man 3 closedir](https://linux.die.net/man/3/closedir) |
| `execve` | [man 2 execve](https://linux.die.net/man/2/execve) |
| `exit` | [man 3 exit](https://linux.die.net/man/3/exit) |
| `_exit` | [man 2 \_exit](https://linux.die.net/man/2/_exit) |
| `fflush` | [man 3 fflush](https://linux.die.net/man/3/fflush) |
| `fork` | [man 2 fork](https://linux.die.net/man/2/fork) |
| `free` | [man 3 free](https://linux.die.net/man/3/free) |
| `getcwd` | [man 3 getcwd](https://linux.die.net/man/3/getcwd) |
| `getline` | [man 3 getline](https://linux.die.net/man/3/getline) |
| `isatty` | [man 3 isatty](https://linux.die.net/man/3/isatty) |
| `kill` | [man 2 kill](https://linux.die.net/man/2/kill) |
| `malloc` | [man 3 malloc](https://linux.die.net/man/3/malloc) |
| `open` | [man 2 open](https://linux.die.net/man/2/open) |
| `opendir` | [man 3 opendir](https://linux.die.net/man/3/opendir) |
| `perror` | [man 3 perror](https://linux.die.net/man/3/perror) |
| `read` | [man 2 read](https://linux.die.net/man/2/read) |
| `readdir` | [man 3 readdir](https://linux.die.net/man/3/readdir) |
| `signal` | [man 2 signal](https://linux.die.net/man/2/signal) |
| `stat` | [(\_\_xstat) man 2 stat](https://linux.die.net/man/2/stat) |
| `lstat` | [(\_\_lxstat) man 2 lstat](https://linux.die.net/man/2/lstat) |
| `fstat` | [(\_\_fxstat) man 2 fstat](https://linux.die.net/man/2/fstat) |
| `strtok` | [man 3 strtok](https://linux.die.net/man/3/strtok) |
| `wait` | [man 2 wait](https://linux.die.net/man/2/wait) |
| `waitpid` | [man 2 waitpid](https://linux.die.net/man/2/waitpid) |
| `wait3` | [man 2 wait3](https://linux.die.net/man/2/wait3) |
| `wait4` | [man 2 wait4](https://linux.die.net/man/2/wait4) |
| `write` | [man 2 write](https://linux.die.net/man/2/write) |

## Authors

 - Farouk Ashraf Elshamy [@FaroukAshrafElshamy](https://github.com/FaroukAshrafElshamy) 

