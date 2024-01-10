#include "main.h"

/**
 * arrayfree - function used to free memory
 * @arr: Argument count
 * Return: free array
 */
void arrayfree(char **arr)
{
	int i;

	if (!arr)
	{
		return;
	}
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]), arr[i] = NULL;
	}
	free(arr), arr = NULL;
}

/**
 * array_rev - a function reverse an array
 * @arr: array
 * @len: length of arr
 * Return: no return
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}
