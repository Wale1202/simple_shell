#include "main.h"

/**
 * displayerror - a function that display error message
 * @name: name
 * @cmd: command
 * @idx: index
 * Return: Returns nothing just display
 */
void displayerror(char *name, char *cmd, int idx)
{
	char *index, message[] = ": not found\n";

	index = _itoa(idx);
	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, message, strlen(message));
	free(index);
}
