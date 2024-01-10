#include "shell.h"

/**
 * get_envaron - the function returns the string array copy of our environ
 * @info: the Structure containing potential arguments to be Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
char *get_envaron(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _resetenv - the function should Remove an environment variable
 * @info: The Structure containing potential arguments to be Used to maintain
 * constant function prototype.
 * Return: 1 delete, 0 otherwise
 * @var: the string env var property
 */
int _resetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
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
 * _settenv - new environment variable,initialized
 * or modify an existing one
 * @info: The  Structure containing potential arguments to be Used to maintain
 * constant function prototype.
 * @var: the string env var property
 * @value: string env var value
 * Return: Always 0
 */
int _settenv(info_t *info, char *var, char *value)
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
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}

