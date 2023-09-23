#include "main.h"

/**
 * dsam_chars - duplicates characters
 * @path_str: the PATH string
 * @start: initializing our var
 * @stop: call our stopping var
 *
 * Return: pointer to new buffer
 */
char *dsam_chars(char *path_str, int start, int stop)
{
	static char buffer[1024];
	int x = 0, y = 0;

	for (y = 0, x = start; x < stop; x++)
		if (path_str[x] != ':')
			buffer[y++] = path_str[x];
	buffer[y] = 0;
	return (buffer);
}

/**
 * fpath - finds the PATH to the CMD strings
 * @details: our information block
 * @pstr: the PATH string
 * @command: the cmd to find
 *
 * Return: return ** of cmd if found or NULL
 */
char *fpath(info_t *details, char *pstr, char *command)
{
	int i = 0, curr_pos = 0;
	char *p;

	if (!pstr)
		return (NULL);
	if ((_strlen(command) > 2) && starts_with(command, "./"))
	{
		if (our_cmd(details, command))
			return (command);
	}
	while (1)
	{
		if (!pstr[i] || pstr[i] == ':')
		{
			p = dup_chars(pstr, curr_pos, i);
			if (!*path)
				_strcat(p, command);
			else
			{
				_strcat(p, "/");
				_strcat(p, command);
			}
			if (our_cmd(details, p))
				return (p);
			if (!pstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

/**
 * our_cmd - determines if a file is an executable command
 * @details: our information block
 * @p: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int our_cmd(info_t *details, char *p)
{
	struct stat st;

	(void)details;
	if (!p || stat(p, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
