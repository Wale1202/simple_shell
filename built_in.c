#include "main.h"

/**
 * check_builtin - Entry point to program
 * @command: command is to be checked
 * Return: Returns 0 for success, 1 for fauiler
 */
int check_builtin(char *command)
{
	int i = 0;
	char *buitins[] = {
		"exit", "env", "setenv", "cd", NULL
	};

	while (buitins[i])
	{
		if (strcmp(command, buitins[i]) == 0)
		{
			return (1);
		}
		i++;
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
 * handle_exit - a function handling exit
 * @command: Argument count
 * @argv: Argument vector
 * @status: status
 * @idx: index
 * Return: Returns exit conditions
 */
void handle_exit(char **command, char **argv, int *status, int idx)
{
	int exit_value = (*status);
	char *index, mssg[] = ": exit: Illegal number: ";

	if (command[1])
	{
		if (is_positive(command[1]))
		{
			exit_value = _atoi(command[1]);
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
	exit(exit_value);
}

/**
 * print_env - a function that display enviroments
 * @command: command
 * @status: status
 * Return: Returns enviroment variables
 */
void print_env(char **command, int *status)
{
	int i;
	(void) status;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	arrayfree(command);
	(*status) = 0;
}
