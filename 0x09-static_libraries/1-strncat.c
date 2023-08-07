#include "main.h"
/**
 * _strncat - concatenate 2 strings
 * uses at most n bytes from src
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int u;
	int j;

	u = 0;
	while (dest[u] != '\0')
	{
		u++;
	}
	j = 0;
	while (j < n && src[j] != '\0')
	{
	dest[u] = src[j];
	u++;
	j++;
	}
	dest[u] = '\0';
	return (dest);
}
