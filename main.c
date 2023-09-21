#include "main.h"

/**
 * main - displays our entry point of the file
 * @ac: our count argument
 * @av: our vector 
 * Return: Always return (0) when successful, (1) on error
 *
 */

int main(int ac, char **av)
{
	int i = 2;
	info_t details[] = {INFO_INIT};
	
	if (ac == 2)
	{
		i = open(av[1], O_RDONLY);
		if (i == -1)
		{
			if(err == EACCES)
				extit(126);
			if (err == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open file");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		details->readfd = i;
		read_history(details);
		hsh(details, av);
		return (EXIT_SUCCESS);
	}
}
