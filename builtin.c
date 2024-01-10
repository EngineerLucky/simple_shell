#include "shell.h"

/**
 * _exiting - The shell must be exited by the exit
 * @info: The Structures containing potential arguments, must be used
 * in constant function prototype.
 * Return: exits status should be given
 * (0) if info.argv[0] != "exit"
 */
int _exiting(info_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* if there is an exit arguement */
	{
		exitcheck = _eratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_ero(info, "Illegal number: ");
			_eput(info->argv[1]);
			_eputcha('\n');
			return (1);
		}
		info->err_num = _eratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _forcd - For the directory of the process that should be changed
 * @info: the Structure containing potential arguments must be  Used to mentan
 * constant function prototype.
 * Return: Always 0
 */
int _forcd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _setenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = int _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (strcmp(info->argv[1], "-") == 0)
	{
		if (!int _getenv(info, "OLDPWD="))
		{
			puts(s);
			putchar( '\n');
			return (1);
		}
		puts(_getenv(info, "OLDPWD=")), putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = int _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_ero(info, "can't cd to ");
		_eput(info->argv[1]), _eputcha('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", int _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _ourhelp - current directory of the process should change
 * @info: the Structure containing potential arguments that are Used to manten
 * constant function prototype.
 * Return: Always 0
 */
int _ourhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	puts("help call works. Function not  implemented \n");
	if (0)
		puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
