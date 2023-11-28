#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *alloc_buf(char *file);
void close_fd(int fd);

/**
 * alloc_buf - Allocate 1024 bytes for a buffer.
 * @file: The associated file name.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *alloc_buf(char *file)
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

/**
 * close_fd - Close file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_fd(int fd)
{
	int status;

	status = close(fd);

	if (status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copy contents of a file to another file.
 * @argc: Number of program arguments.
 * @argv: Array of argument strings.
 *
 * Return: 0 on success.
 *
 * Description: Exit codes:
 * 97 - Incorrect argument count.
 * 98 - File_from doesn't exist or can't be read.
 * 99 - File_to can't be created or written to.
 * 100 - File_to or file_from can't be closed.
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = alloc_buf(argv[2]);
	src_fd = open(argv[1], O_RDONLY);
	bytes_read = read(src_fd, buffer, 1024);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (src_fd == -1 || bytes_read == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		bytes_written = write(dest_fd, buffer, bytes_read);
		if (dest_fd == -1 || bytes_written == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		bytes_read = read(src_fd, buffer, 1024);
		dest_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (bytes_read > 0);

	free(buffer);
	close_fd(src_fd);
	close_fd(dest_fd);

	return (0);
}
