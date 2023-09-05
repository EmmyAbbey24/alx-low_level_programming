#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: text file being read
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
if (filename == NULL)
return (0);

int fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

char *buffer = malloc(letters);
if (buffer == NULL)
{
close(fd);
return (0);
}

ssize_t bytes_read = read(fd, buffer, letters);
if (bytes_read == -1)
bytes_read = 0;

ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

free(buffer);
close(fd);

return (bytes_read == bytes_written) ? bytes_read : (0);
}
