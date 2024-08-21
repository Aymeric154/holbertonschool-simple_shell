# holbertonschool-simple_shell

## Description
Simple Shell is a replica of a Unix shell, written in C. It allows you to execute commands interactively or non-interactively. This project was carried out as part of the Holberton School program, with the goal of better understanding the fundamental concepts of the Unix operating system, such as process management, system calls, and command environments.

## Features

**Interactive mode**: The shell displays a prompt, waits for a command from the user, executes it, and then displays the prompt again. You can execute interactive mode with
./simple_shell 

You should see a prompt where you can type commands:
```bash
Shell$ <span style="color: #DFAF2C">ls </span> or <span style="color: #DFAF2C">/bin/ls </span>

file1 file2 file3 ...

Shell$ <span style="color: #FF0000">exit</span>
```

**Non-interactive mode**: The shell can execute a series of commands provided via a file or stream redirection. You can execute Non-interactive mode with:
```bash
echo <span style="color: #DFAF2C">"/bin/ls"</span> | ./simple_shell
```

**Built-in commands**:

 - exit: Exits the shell
   
 - env: Displays the current environment variables.

**Command management**: The shell searches for executables in the directories defined by the PATH environment variable and executes the corresponding commands.

**Error Handling**: If a command is not found or an error occurs, an appropriate error message is displayed.

## Files

**main.c** : Contains the main function and manages the shell's main loop.

**execute_command.c** : Manages the execution of external commands.

**builtins.c** : Implements builtins like exit and env.

**prompt.c**: handles displaying the prompt and waiting for user input.

**main.h**: Contains function prototypes and global variable declarations.

**README.md**: The file you are currently reading.

**man_1_simple_shell** : The man page for the shell.

## Compilation
To compile this project with `gcc`, use the following command:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
   ```
and then launch the shell with this command:
```bash
./simple_shell
```

