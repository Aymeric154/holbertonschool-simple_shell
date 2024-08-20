#include "main.h"
/**
 * execute_command - Executes a command in a child process.
 * @command: The command to be executed.
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char *argv[2];
	char *cmd_path;

	if (command == NULL || *command == '\0')
		return;

	if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	if (command[0] == '/' || command[0] == '.')
	{
		cmd_path = command;
	}
	else
	{
		cmd_path = find_command_in_path(command);
		if (cmd_path == NULL)
		{
			fprintf(stderr, "./shell: %s: command not found\n", command);
			return;
		}
	}

	argv[0] = cmd_path;
	argv[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		if (cmd_path != command)
			free(cmd_path);
		return;
	}
	else if (pid == 0)
	{
		if (execve(cmd_path, argv, environ) == -1)
		{
			perror("./shell");
			if (cmd_path != command)
				free(cmd_path);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			return;
		}

		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
				fprintf(stderr, "./shell: Child exited with status %d\n", exit_status);
		}
	}

	if (cmd_path != command)
		free(cmd_path);
}
