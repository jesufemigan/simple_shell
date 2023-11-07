#include "main.h"

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
	char *command = NULL, *command_cpy = NULL;
	size_t len;
	ssize_t read;
	char *delimeter = " \n";
	int command_count = 0, i = 0, counter;
	char *token;
	char **argv;

	len = 0;

	while (1)
	{
		printf("($) ");
		read = getline(&command, &len, stdin);

		if (read == -1)
		{
			printf("\n");
			return (-1);
		}
		command_cpy = malloc(sizeof(char) * read);
		if (command_cpy == NULL)
		{
			perror("hsh: unable to allocate memory");
			return (-1);
		}
		strcpy(command_cpy, command);

		token = strtok(command_cpy, delimeter);

		while (token != NULL)
		{
			command_count++;
			token = strtok(NULL, delimeter);
		}
		command_count++;

		argv = malloc(sizeof(char *) * command_count);

		token = strtok(command_cpy, delimeter);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delimeter);
		}
		argv[i] = NULL;

		execmd(argv);

	}

	free(argv);
	free(command);
	free(command_cpy);

	return (0);
}
