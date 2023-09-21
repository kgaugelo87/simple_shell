#include "main.h"

/**
 * strtow - strings that needs to be splited
 * @str: our user input string
 *
 * Return: return the pointer to our array
 *
 */

char **strtow(char *str)
{
	char *array = NULL;
	int i = 0, j = 0, k;

	if (str[0] == NULL || str == NULL)
		return (NULL);
	array = malloc((i + j + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	for (k = 0; k < i; k++)
		array[k] = str[k];
	i = k;
	for (k = 0; k < j; k++)
	{
		array[i] = str[k];
		i++;
	}
	array[i] = '\0';
	return (NULL);
}
