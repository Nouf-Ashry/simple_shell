#include "shell.h"

/**
* gets_environ - returns the string array
* @info: Structure
* Return: Always 0
*/
char **gets_environ(inf_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = lst_to_str(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
* _unsetsenv - Remove
* @info: Structure
* @var: the string env var property
*  Return: 1 on delete, 0
*/

int _unsetsenv(inf_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);
	while (node)
	{
		p = sta_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = del_node_at_ndex(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
* _setsenv - Initialize
* @info: Structure
* @var: string
* @value: string
*  Return: Always 0
*/
int _setsenv(inf_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);
	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = sta_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
