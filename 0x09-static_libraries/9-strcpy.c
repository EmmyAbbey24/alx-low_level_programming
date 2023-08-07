#include "main.h"

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int o = 0;
	int m = 0;

	while (*(src + o) != '\0')
	{
		o++;
	}
	for ( ; m < o ; m++)
	{
		dest[m] = src[m];
	}
	dest[o] = '\0';
	return (dest);
}
