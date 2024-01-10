#include "main.h"

/**
 * arrayfree - function used to free memory in the shell
 * @arr: Argument
 * Return: free aiirray
 */
void arrayfree(char **arr)
{
	int j;

	if (!arr)
	{
		return;
	}
	for (j = 0; arr[j]; j++)
	{
		free(arr[j]), arr[j] = NULL;
	}
		free(arr), arr = NULL;
}

/**
 * array_rev - a function reverse an array
 * @arr: array
 * @len: length of array
 * Return: no return
 */
void array_rev(char *arr, int len)
{
	int j;
	char tmp;

	for (j = 0; j < (len / 2); j++)
	{
		tmp = arr[j];
			arr[j] = arr[(len - 1) - j];
		arr[(len - 1) - j] = tmp;
	}
}
