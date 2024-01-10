#include "main.h"

/**
 * is_positive - a function that check a number is positive
 * @str: string to check
 * Return: Returns 1 for success
 */
int is_positive(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
