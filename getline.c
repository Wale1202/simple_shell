#include "main.h"

/**
 * mygetline - Fuction that gets input
 *
 * Description: the function return input
 * Return: returns input (success)
 */
char *mygetline(void)
{
	char *input = NULL;
	size_t length = 0;
	ssize_t checker;

	checker = getline(&input, &length, stdin);
	if (checker == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
