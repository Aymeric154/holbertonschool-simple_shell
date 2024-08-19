#include "main.h"

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		prompt();
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		if (is_builtin_command(line))
			execute_command(line);
		else
			execute_command(line);
	}

	free(line);
	return (0);
}
