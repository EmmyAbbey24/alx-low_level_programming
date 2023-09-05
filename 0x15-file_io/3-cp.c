#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Print an error message to stderr and exit with the given code.
 * @code: The exit code.
 * @format: The format string for the error message.
 * @...: Additional arguments to format.
 */
void error_exit(int code, const char *format, ...)
{
va_list args;
va_start(args, format);
dprintf(STDERR_FILENO, format, args);
va_end(args);
exit(code);
}

/**
 * main - Copy the content of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, or an exit code on failure.
 */
int main(int argc, char *argv[])
{
int file_from, file_to;
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

if (argc != 3)
error_exit(97, "Usage: cp file_from file_to\n");

file_from = open(argv[1], O_RDONLY);
if (file_from == -1)
error_exit(98, "Error: Can't read from file %s\n", argv[1]);

file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (file_to == -1)
error_exit(99, "Error: Can't write to %s\n", argv[2]);

while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(file_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
error_exit(99, "Error: Can't write to %s\n", argv[2]);
}

if (bytes_read == -1)
error_exit(98, "Error: Can't read from file %s\n", argv[1]);

if (close(file_from) == -1)
error_exit(100, "Error: Can't close fd %d\n", file_from);

if (close(file_to) == -1)
error_exit(100, "Error: Can't close fd %d\n", file_to);

return (0);
}
