# PROJECT TITLE: 0x16. C - Simple Shell

### A Readme file describing this project

This is our simple shell program that provides a command-line interface for executing commands and managing processes. It allows users to interact with the system by entering commands and receiving corresponding outputs.

	* This project is about UNIX command line interpreters (bash, sh, etc.).
	* This program is written in C programming language.
	* This project utilizes different system calls and functions.

## Usage

To run the shell program, compile the source code and execute the resulting executable file. The program accepts command-line arguments as follows:

Copy

```
$ ./hsh [arg1] [arg2]

```

### Features of Shell

*  Command Execution: The shell can execute both built-in-commands & external commands available in the system.
*  Input Handling: The shell reads user input from the command line and processes it..
*  Prompt Display: The shell displays a prompt indicating that it is ready to accept user commands.
*  Built-in Commands: The shell supports various built-in commands, such as `cd`, `exit`, and others, providing additional functionality.
*  Signal Handling: The shell handles signals such as Ctrl+C (SIGINT) and Ctrl+Z (SIGTSTP) to provide a smooth user experience.
*  Background Processes: The shell supports executing commands in the background, allowing users to continue interacting with the shell while a process runs.

### Compilation

To compile the shell program, use the following command:

Copy

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o shell_program

```

NB: Make sure to have all the required source code files in the same directory.

### Execution

To run the compiled shell program, use the following command:

Copy

```
$ ./hsh
```

Once executed, the shell will display a prompt indicating that it is ready to accept commands. Enter commands and press Enter to execute them.

## Built-in-Commands

The shell supports the following built-in-commands:

* `cd [directory]`: Change the current working directory to the specified directory. If no directory is provided, it changes to the user's home directory.
* `exit`: Exit the shell program.
* `env`: print or display environment

### Acknowledgement
This program was written and designed by [Fagbodun Adewale Iyanuoluwa](./https://github.com/Wale1202) and [Mathias Owa Martins](./https://github.com/montybasquiart).
We are learners and constantly improving daily. Feel free to reach us if you encounter any questions.
