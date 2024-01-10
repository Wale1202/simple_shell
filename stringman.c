#include "main.h"

/**
 * integerlength - a function used for to tell length of string
 * @number: number
 * Return: Returns length
 */
int integerlength(int number)
{
	int length = 0;

	while (number != 0)
	{
		length++;
		number /= 10;
	}
	return (length);
}

/**
 * _itoa - a function for string man
 * @n: number input
 * Return: Returns s
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = integerlength(n);
	s = malloc(len + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0';

	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}

	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';

	return (s);
}

/**
 * _atoi - a function that get string and counts
 * @str: string input
 * Return: number
 */
int _atoi(char *str)
{
	int i = 0, number = 0;

	while (str[i])
	{
		number *= 10;
		number += (str[i] - '0');
		i++;
	}

	return (number);
}
