#include "main.h"

/**
 * execute_command - Executes a command in a child process.
 * @command: The command string to be executed.
 */

void execute_command(char *command)
{
	pid_t pid;
	int status;
	char **argv;
	char *cmd_path;

	argv = parse_command(command);  /* Parse the command string */

	if (argv == NULL || argv[0] == NULL)
	{
		free(argv);
		return;
	}

	if (argv[0][0] == '/' || argv[0][0] == '.')
		cmd_path = argv[0];  /* Absolute or relative path */
	else
	{
		cmd_path = find_command_in_path(argv[0]);
		if (cmd_path == NULL)
		{
			write(2, "Command not found\n", 18);  /* Handle error */
			free(argv);
			return;
		}
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(argv);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)  /* Child process */
	{
		if (execve(cmd_path, argv, environ) == -1)
		{
			perror("./shell");
			free(argv);
			_exit(EXIT_FAILURE);
		}
	}
	else  /* Parent process */
		wait(&status);

	if (cmd_path != argv[0])
		free(cmd_path);
	free(argv);  /* Free the argument array */
}

