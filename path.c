#include "main.h"

/**
 * find_command_in_path - Searches for an executable command
 * in the directories listed in PATH.
 * @command: The command to find.
 *
 * Return: The full path to the command
 * if found and executable, otherwise NULL.
 */

char *find_command_in_path(const char *command)
{
	char *path_env = getenv("PATH");
	char path[PATH_MAX];
	char *token;

	if (command[0] == '/' && access(command, X_OK) == 0)
	{
		return (strdup(command));
	}

	if (path_env == NULL)
	{
		return (NULL);
	}

	token = strtok(path_env, ":");
	while (token != NULL)
	{
		snprintf(path, sizeof(path), "%s/%s", token, command);
		if (access(path, X_OK) == 0)
		{
			return (strdup(path));
		}
		token = strtok(NULL, ":");
	}

	return (NULL);
}
