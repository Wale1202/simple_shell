#include "main.h"

/**
 * _getenv - a function that get enviroment
 * @name: name
 * Return: Returns env for success, NULL for failer
 */
char *_getenv(char *name)
{
	char *tmp;
	char *key;
	char *value;
	char *env;
	int i = 0;

	while (environ[i])
	{
		tmp = strdup(environ[i]);
		key = strtok(tmp, "=");
		if (strcmp(key, name) == 0)
		{
			value = strtok(NULL, "\n");
			env = strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp);
		tmp = NULL;
		i++;
	}
	return (NULL);
}
