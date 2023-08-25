#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * _strtok - Custom implementation of the strtok function.
 * @str: The string to tokenize.
 * @delimiter: The delimiter used for tokenization.
 */
void _strtok(const char *str, char delimiter)
{
	int len = strlen(str);
	char* word = (char*)malloc((len + 1) * sizeof(char));
	int i, n;

	for (i = 0; i <= len; i++)
	{
		n = 0;
		if (str[i] == delimiter || str[i] == '\0')
			word[n] = '\0';
		if (n > 0)
		{
			printf("%s\n", word);
			n = 0;
		}
		else
		{
			word[n++] = str[i];
		}
	}
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	char *str = "This is another word with spaces";
	char *stc = malloc(sizeof(char) * strlen(str));
	char delim[3] = ", ";
	char *trunks;
	int i;

	strcpy(stc, str);
	trunks = strtok(stc, delim);

	while (trunks != NULL)
	{
		printf("%s\n", trunks);
		trunks = strtok(NULL, delim);
	}

	for (i = 0; i < 35; i++)
	{
	if (stc[i] == '\0')
		printf("\\0");
	else
		printf("%c", stc[i]);
	}
	free(stc);

	_strtok("This is another word with spaces", ' ');

	return (0);
}
