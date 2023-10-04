#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *alloc_buffer(char *file);
void close_fd(int fd);

/**
 * alloc_buffer - Allocate a 1024-byte buffer.
 * @file: The associated file name.
 *
 * Return: Pointer to the newly-allocated buffer.
 */
char *alloc_buffer(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buf);
}

