#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t nread;
	char *line;

	while (1)
	{
		prompt();
		nread = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);

		if (nread == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}

		if (nread == 0)
		{
			exit(EXIT_SUCCESS);
		}

		buffer[nread] = '\0';

		/* Removing trailing newline if present */
		if (buffer[nread - 1] == '\n')
			buffer[nread - 1] = '\0';

		/* Processing the input */
		line = buffer;
		if (strcmp(line, "exit") == 0)
			handle_exit(line);
		else if (strcmp(line, "env") == 0)
			handle_env(line);
		else
			execute_command(line);
	}

	return (0);
}

