#include "main.h"

/**
 * _getpath - a function that path  enviroment variable
 * @command: command
 * Return: Returns PATH for success, NULL for failer
 */
char *_getpath(char *command)
{
	char *full_cmd;
	char *path_env;
	char *directory;
	int i = 0;
	struct stat st;

	while (command[i])
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (strdup(command));
			return (NULL);
		}
		i++;
	}
	path_env = _getenv("PATH");

	if (!path_env)
		return (NULL);
	directory = strtok(path_env, ":");

	while (directory)
	{
		full_cmd = malloc(strlen(directory) + strlen(command) + 2);
		if (full_cmd)
		{
			strcpy(full_cmd, directory);
			strcat(full_cmd, "/");
			strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			directory = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
