#include "main.h"

/**
 * prompt - Displays a shell prompt if the input is from a terminal.
 *
 * This function checks if the standard input (stdin) is a terminal.
 * If it is, it prints a prompt (`#shell$ `) to the standard output.
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Shell$ ", 8);
}
