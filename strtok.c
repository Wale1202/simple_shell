#include "main.h"

/**
 * mystrtok - tokenizer function for shell input
 * @input: input is to be tokenized
 * Return: Returns command
 */
char **mystrtok(char *input)
{
	char *token = NULL;
	char *input_copy = NULL;
	char **command = NULL;
	int token_count = 0;
	int i = 0;

	if (!input)
	{
		return (NULL);
	}
	input_copy = strdup(input);
	token = strtok(input_copy, DELIM);

	if (token == NULL)
	{
		free(input);
		free(input_copy);
		return (NULL);
	}
	while (token)
	{
		token_count++;
		token = strtok(NULL, DELIM);
	}
	free(input_copy);
	command = malloc(sizeof(char *) * (token_count + 1));
	if (!command)
	{
		free(input);
		return (NULL);
	}
	token = strtok(input, DELIM);

	while (token)
	{
		command[i] = strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(input);
	command[i] = NULL;
	return (command);
}
