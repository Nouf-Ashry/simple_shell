#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "shell.h"

/**
 * main - stat
 *
 * @argc: The argument count indicating the number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: Always 0.
 */
/* Accessing command-line arguments */
int main(int argc, char **argv)
{
	unsigned int i;
	struct stat st;

	if (argc < 2)
	{
		printf("Usage: %s path_to_file ...\n", argv[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printf("%s:", av[i]);
		if (stat(av[i], &st) == 0)
		{
			printf(" FOUND\n");
		}
		else
		{
			printf(" NOT FOUND\n");
		}
		i++;
	}
	return (0);
}
