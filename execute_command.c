#include "main.h"

#define MAX_ARGS 64

/**
 * parse_command - Tokenizes the command string into arguments.
 * @command: The command to parse.
 * @argv: The array to store the arguments.
 *
 * Return: The number of arguments parsed.
 */
int parse_command(char *command, char *argv[])
{
	char *token;
	int i = 0;

	token = strtok(command, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
	return (i);
}

/**
 * handle_builtin - Handles built-in commands.
 * @argv: The array of arguments.
 *
 * Return: 1 if the command is handled, otherwise 0.
 */
int handle_builtin(char *argv[])
{
	if (strcmp(argv[0], "exit") == 0)
	{
		handle_exit(NULL);
		return (1);
	}
	if (strcmp(argv[0], "env") == 0)
	{
		handle_env(NULL);
		return (1);
	}
	return (0);
}

/**
 * execute_command - Executes a given command.
 * @command: The command to execute.
 *
 * Description: Parses the command, handles built-in commands, and executes
 *              the command using execve in a child process.
 */

void execute_command(char *command)
{
	char *argv[2];
	pid_t pid;
	int status;

	parse_command(command, argv);

	if (handle_builtin(argv))
	{
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return;
	}
	if (pid == 0)
	{
		execvp(argv[0], argv);
		perror("execvp failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait failed");
		}
		else
		{
			if (WIFEXITED(status))
			{
				printf("Child exited with status %d\n", WEXITSTATUS(status));
			}
			else if (WIFSIGNALED(status))
			{
				printf("Child terminated by signal %d\n", WTERMSIG(status));
			}
		}
	}
}
