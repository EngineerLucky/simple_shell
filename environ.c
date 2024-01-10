#include "shell.h"

/**
 * _thenv - the current environment should be printed
 * @info: Structures containing potential arguments should be Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _thenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _putenv - value of an environ variable should be gotten
 * @info: the Structure containing potential arguments should be Used to mentan
 * @name: env var name
 *
 * Return: the value
 */
char *_putenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *x;

	while (node)
	{
		x = starts_with(node->str, name);
		if (x && *x)
			return (x);
		node = node->next;
	}
	return (NULL);
}

/**
 * _setenv - the function must Initialize variable should be initialised
 * or modify the existing one
 * @info: the Structures containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _setenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eput("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _unsetenv - the environment variable should be removed
 * @info: the Structure containing potential argument should be Used to mentan
 * constant function prototype.
 *  Return: Always 0
 */
int _unsetenv(info_t *info)
{
	int m;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (m = 1; m <= info->argc; m++)
		_unsetenv(info, info->argv[m]);

	return (0);
}

/**
 * popul_env_list - it must populates env linked list
 * @info: the Structure containing potential argument to be Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int popul_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t b;

	for (b = 0; environ[b]; b++)
	add_node_end(&node, environ[b], 0);
	info->env = node;
	return (0);
}
