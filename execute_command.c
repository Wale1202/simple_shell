#include "main.h"

/**
 * myexecute - a function that execute command
 * @command: command
 * @argv: Argument vector
 * @idx: index
 * Return: Returns execution
 */
int myexecute(char **command, char **argv, int idx)
{
	char *command_full;
	pid_t child;
	int status;

	command_full = _getpath(command[0]);
	if (!command_full)
	{
		displayerror(argv[0], command[0], idx);
		arrayfree(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(command_full, command, environ) == -1)
		{
			free(command_full);
			arrayfree(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		arrayfree(command);
		free(command_full);
	}
	return (WEXITSTATUS(status));
}
