#include "main.h"

void handle_exit(char command)
{
	if (strcmp(command, "exit") == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
}

void handle_env(charcommand)
{
	char *env;

	if (strcmp(command, "env") == 0)
	{
		env = environ;
		while (env != NULL)
		{
			printf("%s\n", env);
			env++;
		}
	}
}

int is_builtin_command(charcommand)
{
	if (strcmp(command, "exit") == 0)
	{
		handle_exit(command);
		return 1;
	}
	else if (strcmp(command, "env") == 0)
	{
		handle_env(command);
		return 1;
	}
	return 0;
}
