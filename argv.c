#include <stdio.h>
#include "shell.h"

/**
 * main - Print Arguments
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int i;

	while (*argv != NULL)
	{
		printf("argv = %s\n", *argv);
		argv++;
	}

	return (0);
}
