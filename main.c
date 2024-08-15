#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
    
	signal(SIGINT, SIG_IGN); /* Ignore Ctrl+C */

	while (1)
	{
		prompt();
		nread = getline(&line, &len, stdin);
        
		if (nread == -1) /* Handle EOF (Ctrl+D) */
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		if (line[nread - 1] == '\n') /* Remove trailing newline character */
			line[nread - 1] = '\0';

		if (is_builtin_command(line))
		{
			continue; /* Execute built-in commands directly */
		}

		execute_command(line);
	}

	free(line);
	return 0;
}

