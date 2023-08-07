#include "main.h"
/**
 * _strncpy - to copy a string
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int u;

	u = 0;
	while (u < n && src[u] != '\0')
	{
		dest[u] = src[u];
		u++;
	}
	while (u < n)
	{
		dest[u] = '\0';
		u++;
	}

	return (dest);
}
