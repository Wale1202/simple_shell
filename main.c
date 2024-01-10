#include "main.h"

/**
 * main - Entry point
 *
 * Description: This is main program
 * @ac: Number of argument
 * @argv: The actual arguments
 * Return: Returns 0 (success)
 */
int main(int ac, char **argv)
{
char *input = NULL;
char **command = NULL;
int i = 0;
int stat = 0;
(void) ac;

while (1)
{
	displayprompt();
	input = mygetline();
	if (input == NULL)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		return (stat);
	}

	i++;
	command = mystrtok(input);
	if (!command)
	{
		continue;
	}

	if (check_builtin(command[0]))
	{
		handle_builtin(command, argv, &stat, i);
	}
	else
	{
		stat = myexecute(command, argv, i);
	}
}

}
