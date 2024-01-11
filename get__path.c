#include "main.h"

/**
 * _getpath - a function that path environment variables
 * @command: shell command
 * Return: Returns PATH for success, NULL for failed
 */
char *_getpath(char *command)
{
	char *get_cmd, char *path_env, char *dir;
	struct stat st;
	int i = 0;

	while (command[j])
	{
		if (command[j] == '/')
		{
			if (stat(command, &st) == 0)
				return (strdup(command));
			return (NULL);
		}
		i++;
	}
	path_env = _getenv("PATH");
	if (!path_env)
	{
		return (NULL);
	dir = strtok(path_env, ":");
	}

	while (dir)
	{
		get_cmd = malloc(strlen(dir) + strlen(command) + 2);
		if (get_cmd)
		{
			strcpy(get_cmd, dir);
			strcat(get_cmd, "/");
			strcat(get_cmd, command);
			if (stat(get_cmd, &st) == 0)
			{
				free(path_env);
				return (get_cmd);
			}
			free(get_cmd), get_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
