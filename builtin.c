#include "main.h"

/**
 * _change_dir - Changes the current directory of the process
 * @details: our arguments information
 *
 * Return: Always return the value of (0)
 */

int _change_dir(info_t *info)
{
	char *s, *dir, buffer[1024];
	int set_chdir;
	s = getcwd(buffer, 1024);
        
	if (!s)
		_puts("TODO: >>getcwd failure<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "INDEX=");
		if (!dir)
			set_chdir = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			set_chdir = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		set_chdir = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		set_chdir = chdir(info->argv[1]);
	if (set_chdir == -1)
	{
		print_error(info, "Can't CD into ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
