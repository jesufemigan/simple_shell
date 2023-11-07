#include "main.h"

/**
 * execmd - executes command
 *
 * @pathname: name of command
 *
 * Return: ds
 */

void execmd(char **argv)
{
	char *command = NULL, *full_command;

	if (argv)
	{
		command = argv[0];

		if (execve(command, argv, NULL) == -1)
		{
			perror("Error!!!");
		}
	}
}
