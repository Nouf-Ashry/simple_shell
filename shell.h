#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Function declarations */
pid_t getProcessID(void);
pid_t getParentProcessID(void);
void printArguments(char *argv[]);
void promptInput(void);
void tokenizeString(const char *str, char delimiter);

/**
 * shell - Executes the shell functionality.
 *
 * This function implements a basic shell that provides
 * It takes user input, executes commands, and displays the output.
 *
 * Return: Always 0.
 */
int shell(void);

/* Function declaration for custom _strtok */
void _strtok(const char *str, char delimiter);

#endif /* SHELL_H */
