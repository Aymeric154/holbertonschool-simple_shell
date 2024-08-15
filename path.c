#include "main.h"

char find_command_in_path(charcommand)
{
	char path = getenv("PATH");
	charpath_dup, token,full_path;
	struct stat st;

	if (!path || !command)
		return NULL;

	path_dup = strdup(path);
	if (!path_dup)
		return NULL;

	token = strtok(path_dup, ":");
	full_path = malloc(1024);
	if (!full_path)
	{
		free(path_dup);
		return NULL;
	}

	while (token)
	{
		sprintf(full_path, "%s/%s", token, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_dup);
			return full_path;
		}
		token = strtok(NULL, ":");
	}
	free(path_dup);
	free(full_path);
	return NULL;
}

