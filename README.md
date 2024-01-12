# PROJECT TITLE: 0x16. C - Simple Shell

This project consists of a basic command interpreter (Shell) Created in C Programming language, with several features. It's an intensive coding development project.

## About

The simple_shell is a program that reads user commands prompts through Standard Input Stream and attempts to execute them by means of low level system procedures. This is by using built-in functions and, or searching for executable programs in the Operating System.

The shell comprises of two Operating Modes:

	**Interactive** && **Non-interactive**

In **Interactive mode**, the shell will display a prompt **($)** indicating that the user can write and execute a command. After the command is run, the prompt will appear again a wait for a new command. This can go indefinitely as long as the user does not exit the shell.

    demo@ubuntu:~/simple_shell$ ./hsh
    $ ls
    file1 file2 dir1 dir2
    $ 

While in **Non-interactive mode**, the shell will need to be run with a command input piped into its execution so that the command is run as soon as the Shell starts. In this mode no prompt will appear, and no further input will be expected from the user.

    demo@ubuntu:~/simple_shell$ echo "ls" | ./hsh
    file1 file2 dir2 dir2
    demo@ubuntu:~/simple_shell$
    
In both modes, commands can be written with their absolute path or simply their executable name if they exist in one of the folders defined by the environmental variable PATH or as built in functions of the Shell.

## **Return (Exit Value)**

Upon termination of the simple shell program, an exit value will be set according to the status of the last command executed. If no error was ever encountered, the exit value will be zero (0).

If an error is found, values that can be set are:

	1 - Catchall for general errors

	2 - Misuse of shell builtins

	126 - Command invoked cannot execute

	127 - command not found

	130 - Script terminated by Control-C


## **Format of Command Input**

In order to give commands to the simple shell, these will need to be piped through an echo in case of **Non-interactive mode**.

In **Interactive Mode** the commands will need to be written with a keyboard when the prompt appears and then will be recognized when an enter key is pressed (new line). As soon as this happens, the Shell will attempt to execute the command through several means. In this mode, the program can be exited using the CTRL + D combination, as the CTRL + C signal is reserved only for internal script termination and it does not exit the shell.


## **Arguments**

Most commands have several options or arguments that can be used when executing the program. In order for the Shell to recognize those parameters, the user must separate everything with spaces.

Example:

    demo@ubuntu:~/simple_shell$ ./hsh
    $ ls -l /tmp
    total 0
    $

    
or

    demo@ubuntu:~/simple_shell$ echo "ls -l /tmp" ./hsh
    total 0
    demo@ubuntu:~/simple_shell$

## **Comments**

Commands can be run with an extra parameter called a comment. This parameter is used for writing a descriptory text when executing. In order to use this option
the user will have to add the character '#' after a command or its arguments with a trailing space:  

Example:  

    demo@ubuntu:~/simple_shell$ ./hsh  
    $ ls -l /tmp #This is a comment  
    total 0  
    $  

Everything written after the character '#' will be ignored in the execution.

## **Built Ins**

The simple shell has a set of commands that work like internal functions and don't require the search for any executable program.  

|Built In|Description|
|--|--|
|**exit**|This command is used for exiting the Shell, its syntax is **exit status** , where status is an integer number. If no status is given, exit will use the value set by the last error encountered.|
|**env**|This command is used for displaying the system's current environment in the format **variable=value**. Its syntax is simply **env** with no options.|
|**setenv**| This command will overwrite the value of an environmental variable if it already exists, or create a new one in case it does not. Its syntax is **setenv VARIABLE VALUE**. If no arguments are given, then setenv will print the current environment as if **env** had been used.  |
|**unsetenv**| This command will remove an environmental variable from the system if it exists, or leave the environment untouched if it does not. Its syntax is **unsetenv VARIABLE**. If no argument is given, the environment will remain the same. |
|**cd**|This command is used for changing the current working directory. Its syntax is **cd DIRECTORY**. If no directory is specified, cd will change directory to the value set in the environmental variable **HOME**. If instead of directory, a symbol **-** is used, then cd will change to the previous working directory, which by default is initially **HOME**.  |
|**help**|This command will show a text explaining the usage of a built in. Its syntax is **help BUILTIN**. If this command is run without argument, then a list of all built ins and their syntax will be displayed. This command can be used on itself. |


## Search and Execution

The simple shell will always have the same order of search an execution.

When a command is written and given to the Shell, the Shell will initially check if the command is a built in. If the condition is met, then the command will be executed internally, and the prompt will be displayed again.

If a builtin command is not found, one of two things happen:

**1.** Command names containing a slash are simply executed without performing any searches.

**2.** The shell searches each entry in the environmental variable PATH for the command.  The value of the PATH variable should be a series of entries separated by colons.  Each entry consists of a directory name. The current directory may be indicated implicitly by an empty directory name, or explicitly by a single period.

If the command is found in the PATH, then its executable is run in a sub-process, also called child process, so that after its termination, the Shell does not exit.

If the command is not found, then the Shell will display an error indicating the issue. The Shell will also keep track of the command count and display it when the error appears.

# Getting Started

These instructions will get you a copy of the project up and running on your local machine (Linux distro) for development and testing purposes.

# Installing

To see how the program works, you need to clone the repository of the project from Github. This will contain the simple shell program and all of its dependencies. 

	git clone https://github.com/Wale1202/simple_shell

Once executed, the shell will display a prompt indicating that it is ready to accept commands. Enter commands and press Enter to execute them.

# **Compilation:**

In order to test the HSH simple shell, you will need to open a terminal in a Linux distribution and go to the folder you just cloned from GitHub. In there, you will need to compile the program, which was tested in GNU GCC 5.5.0 with different error flags such as:

> **-Wall:**  Enables all the warnings about constructions.
> 
> **-Wextra :**  Enables some extra warning flags that are not enabled by  **-Wall**.
> 
> **-Werror:**  Make all warnings into hard errors.
> 
> **-pedantic:**  Issue all the mandatory diagnostics listed in the C standard.

The compilation code goes as follows:

    demo@ubuntu:~/simple_shell$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

By default, the name of the executable will be **hsh**, but you can change it if you desire to do so.

**Execution:**

Once the program is compiled you will need to execute the shell with the following code:

**Interactive mode**: 

    demo@ubuntu:~/simple_shell$ ./hsh

**Non-interactive mode**:

    example@ubuntu:~/simple_shell$ echo "command" | ./hsh

## General Use Examples

**Interactive Mode** 

    demo@ubuntu-focal:~/simple_shell$ ./hsh
    $ ls
    file1 file2 dir1 dir2
    $ ls -l
    -rw-rw-r-- 1 vagrant vagrant  1293 Jan 12 22:33 file1
    -rw-rw-r-- 1 vagrant vagrant  4768 Jan 12 22:33 file2
    drwxrwxr-x 2 vagrant vagrant  4096 Jan 12 22:35 dir1
    drwxrwxr-x 2 vagrant vagrant  4126 Jan 12 22:35 dir2
    $ echo Hello
    Hello
    $ qwerty
    \ ./hsh: 4: qwerty: not found
    $ env
    USER=ubuntu
    LANGUAGE=en_US
    SESSION=ubuntu
    COMPIZ_CONFIG_PROFILE=ubuntu
    SHLVL=1
    HOME=/home/vagrant
    DESKTOP_SESSION=ubuntu
    LOGNAME=vagrant
    TERM=xterm-256color
    PATH=/home/vagrant/bin:/home/vagrant/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin
    DISPLAY=:0
    $ exit
    demo@ubuntu-focal:~/simple_shell$

 **Non-interactive Mode**
    
    demo@ubuntu-focal:~/simple_shell$ echo "ls" | ./hsh
    file1 file2 dir1 dir2
    demo@ubuntu-focal:~/simple_shell$ echo "ls -l" | ./hsh
    -rw-rw-r-- 1 vagrant vagrant  1293 Jan 12 22:33 file1
    -rw-rw-r-- 1 vagrant vagrant  4768 Jan 12 22:33 file2
    drwxrwxr-x 2 vagrant vagrant  4096 Jan 12 22:35 dir1
    drwxrwxr-x 2 vagrant vagrant  4126 Jan 12 22:35 dir2
    demo@ubuntu-focal:~/simple_shell$ echo "qwerty" | ./hsh
    ./hsh: 1: qwerty: not found
    demo@ubuntu-focal:~/simple_shell$

## Built with

Ubuntu 22.04.3, Vim, and C language.

# Authors
This program was written by [Fagbodun Adewale Iyanuoluwa](https://github.com/Wale1202) and [Mathias Owa Martins](https://github.com/montybasquiart).
We are learners and constantly improving daily. Feel free to reach us if you encounter any questions.
