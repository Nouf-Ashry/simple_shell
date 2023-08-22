#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "shell.h"

/**
 * main - stat
 *
 * Return: Always 0.
 */
/* Accessing command-line arguments */
int main(int argc, char **argv)
{
	unsigned int i;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
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
