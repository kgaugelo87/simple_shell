#include "main.h"

/**
 * unbound - freeing a string of strings
 * @multi: our strings
 */
void unbound(char **multi)
{
	char **i = multi;

	if (!multi)
		return;
	while (*multi)
		free(*pp++);
	free(i);
}

/**
 * _memset - fills memory with a constant byte
 * @s: memory area to our pointer
 * @b: byte to fill our pointer
 * @n: amount of bytes to be filled
 * Return: returns a pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[i] = b;
	return (s);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to malloc prevously used block
 * @osize: byte size of previous block
 * @size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int size, unsigned int osize)
{
	char *p;

	if (!ptr)
		return (malloc(size));
	if (!size)
		return (free(ptr), NULL);
	if (size == osize)
		return (ptr);

	p = malloc(size);
	if (!p)
		return (NULL);

	osize = osize < size ? osize : size;
	while (osize--)
		p[osize] = ((char *)ptr)[osize];
	free(ptr);
	return (p);
}
