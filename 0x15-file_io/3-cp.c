#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(void);
void close_file(int fd);
void error_exit(const char *message, int exit_code, ...);

/**
 * create_buffer - Allocates a 1024-byte buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
char *buffer = malloc(1024);

if (buffer == NULL)
{
error_exit("Error: Can't allocate memory\n", 99);
}

return buffer;
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
if (close(fd) == -1)
{
error_exit("Error: Can't close fd %d\n", 100, fd);
}
}

/**
 * error_exit - Print an error message to stderr and exit with the given code.
 * @message: The error message format.
 * @exit_code: The exit code.
 * @...: Additional arguments for the error message.
 */
void error_exit(const char *message, int exit_code, ...)
{
va_list args;
va_start(args, exit_code);
vfprintf(stderr, message, args);
va_end(args);
exit(exit_code);
}

int main(int argc, char *argv[])
{
int from, to, r, w;
char *buffer;

if (argc != 3)
{
error_exit("Usage: cp file_from file_to\n", 97);
}

buffer = create_buffer();
from = open(argv[1], O_RDONLY);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

while ((r = read(from, buffer, 1024)) > 0)
{
if (from == -1 || r == -1)
{
error_exit("Error: Can't read from file %s\n", 98, argv[1]);
}

w = write(to, buffer, r);
if (to == -1 || w == -1)
{
error_exit("Error: Can't write to %s\n", 99, argv[2]);
}
}

free(buffer);
close_file(from);
close_file(to);

return 0;
}
