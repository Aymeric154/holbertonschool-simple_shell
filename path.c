#include "main.h"

/**
 * find_command_in_path - Searches for an executable command in PATH.
 * @command: The command to find.
 * Return: The full path if found, otherwise NULL.
 */
char *find_command_in_path(const char *command)
{
	char *path_env = NULL, *path_copy, *token;
	char path[PATH_MAX];
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path_env = environ[i] + 5;
			break;
		}
	}

	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		path[0] = '\0';

		strcat(path, token);
		strcat(path, "/");
		strcat(path, command);

		if (access(path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(path));
		}

		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
