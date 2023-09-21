#include "main.h"

/**
 * _change_dir - Changes the current directory of the process
 * @details: our arguments information
 *
 * Return: Always return the value of (0)
 */

int _change_dir(info_t *details)
{
	char *s, *dir;
	int set_chdir;
	char buffer[1024];

	s = getcwd(buffer, 1024);
        if (!s)
		_puts("TODO: >>getcwd failure<<\n");
	if (!details->argv[1])
	{
		dir = _getenv(details, "HOME=");
		if (!dir)
			set_chdir = chdir((dir = _getenv(details, "PWD=")) ? dir : "/");
		else
			set_chdir = chdir(dir);
	}
	else if (_strcmp(details->argv[1], "-") == 0)
	{
		if (!_getenv(details, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(details, "OLDPWD=")), _putchar('\n');
		set_chdir = chdir((dir = _getenv(details, "OLDPWD=")) ? dir : "/");
	}
	else
		set_chdir = chdir(details->argv[1]);
	if (set_chdir == -1)
	{
		print_error(details, "Can't CD into ");
		_eputs(details->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(details, "OLDPWD", _getenv(details, "PWD="));
		_setenv(details, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
