#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * @ac: count of argument
 * @av: vector
 *
 * Return: int
 */

int main()
{
	char *command;
	size_t bufsize;
	ssize_t read;

	bufsize = 1024;

	command = (char *)malloc(bufsize * sizeof(char));

	while (1)
	{
		printf("($) ");
		read = getline(&command, &bufsize, stdin);

		if (read == -1)
		{
			printf("\n");
			exit(0);
		}
		printf("%s", command);
	}
	free(command);
	return (0);
}
