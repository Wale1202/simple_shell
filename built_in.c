#include "main.h"

/**
 * check_builtin - Entry point to program
 * @command: command is to be checked
 * Return: Returns 0 for success, 1 for fauiler
 */
int check_builtin(char *command)
{
	int k = 0;
	char *buitinss[] = {
		"exit", "env", "setenv", "cd", NULL
	};

	while (buitinss[k])
	{
		if (strcmp(command, buitinss[k]) == 0)
		{
			return (1);
		}
		k++;
	}
	return (0);
}

/**
 * handle_builtin - a function that handle builtin
 * @command: command
 * @argv: Argument vector
 * @status: status
 * @idx: index
 * Return: returns nothing
 */
void handle_builtin(char **command, char **argv, int *status, int idx)
{
	(void) argv;
	(void) idx;

	if (strcmp(command[0], "exit") == 0)
		handle_exit(command, argv, status, idx);
	else if (strcmp(command[0], "env") == 0)
		print_env(command, status);
}

/**
 * handle_exit - a function handling exit for the shell
 * @command: Argument count
 * @argv: Argument vector
 * @status: status for the shell
 * @idx: index
 * Return: Returns exit conditions for the shell
 */
void handle_exit(char **command, char **argv, int *status, int idx)
{
	int exit_values = (*status);
	char *index, mssg[] = ": exit: Illegal number: ";

	if (command[1])
	{
		if (is_positive(command[1]))
		{
			exit_values = _atoi(command[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, strlen(index));
			write(STDERR_FILENO, mssg, strlen(mssg));
			write(STDERR_FILENO, command[1], strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			arrayfree(command);
			(*status) = 2;
			return;
		}
	}
		arrayfree(command);
		exit(exit_values);
}

/**
 * print_env - a function that display enviroments for the shell
 * @command: command for the shell
 * @status: status of the shell
 * Return: Returns Variables for the enviroment
 */
void print_env(char **command, int *status)
{
		int k;
		(void) status;

	for (k = 0; environ[k]; k++)
	{
		write(STDOUT_FILENO, environ[k], strlen(environ[k]));
		write(STDOUT_FILENO, "\n", 1);
	}
	arrayfree(command);
	(*status) = 0;
}
