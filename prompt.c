#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * main - Prompt Input
 *
 * Return: Always 0.
 */

int main(void)
{
	size_t n = 0;
	char *buf = NULL;

	printf("$ ");
	getline(&buf, &n, stdin);
	printf("%s", buf);

	free(buf);

	return (0);
}
