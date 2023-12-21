# Simple Shell
Release date: December 20, 2023

## Introduction

### What is a Shell?

A shell is a command-line interpreter, serving as the interface between users and the operating system. It allows users to access various services and functionalities of the operating system through commands.

### What is the Simple Shell for?

The Simple Shell is designed for interpreting user commands. It encompasses features such as process control, input/output redirection, file listing and reading, security, communication, and a command language for creating batch programs or scripts.

## Documentation

### Installation

1. Clone this repository: `git clone "https://github.com/Ouyei/simple_shell"`
2. Change directories into the repository: `cd simple_shell`
3. Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
4. Run the shell in interactive mode: `./hsh`
5. Or run the shell in non-interactive mode: `echo "Hello world!" | ./hsh`

### Testing

Compile the code using the instructions in the Installation section, and then run the executable file in your terminal.

```bash
$ ./hsh
$
$ ls -l
total 56
-rw-r--r-- 1 root root  238 Dec  6 08:34 AUTHORS
-rwxr-xr-x 1 root root  393 Dec  6 08:39 generate-authors.sh
# ... (output truncated for brevity)
-rw-r--r-- 1 root root 1461 Dec  6 08:34 man_1_simple_shell
-rw-r--r-- 1 root root 7134 Dec  6 08:34 README.md
-rw-r--r-- 1 root root  824 Dec  6 08:39 shell.h

     Authors:
Michael Duarte Morris Castro