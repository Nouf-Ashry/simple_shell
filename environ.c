#include "shell.h"


/**
 * _mineenv -  this  prints the current environ
 * @info: struct
 * Return: Always 0
 */

int _mineenv(info_t *info)
{
	pr_lst_str(info->env);
	return (0);
}

/**
 * _getsenv - gets the value of an environ variable
 * @info:  this struct containing potential arguments.
 * @name: env var name
 * Return: the value
 */
char *_getsenv(inf_t *info, const char *name)
{
	list_t *node = info->env;
	char *q;

	while (node)
	{
		q = sta_with(node->str, name);
		if (q && *q)
			return (q);
		node = node->next;
	}
	return (NULL);
}

/**
 * _minesetenv - Initialize a new envir
 * @info: struct
 *  Return: Always 0
 */
int _minesetenv(inf_t *info)
{
	if (info->argc != 3)
	{
		_erputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setsenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _mineunsetenv - remove envir
 * @info: struct
 * Return: Always 0
 */
int _mineunsetenv(inf_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_erputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetsenv(info, info->argv[i]);
	return (0);
}

/**
 * pop_env_list - populates env
 * @info: structure
 * Return: Always 0
 */
int pop_env_list(inf_t *info)
{
	list_t *nde = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&nde, environ[i], 0);
	info->env = nde;
	return (0);
}
