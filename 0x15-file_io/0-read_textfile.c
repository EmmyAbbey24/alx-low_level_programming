#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints the letters.
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)

{
int fd;
ssize_t rd;
ssize_t wt;
char *buf;

if (!filename)
return (0);

fd = open(filename, O_RDONLY);

if (fd == -1)
return (0);

buf = malloc(sizeof(char) * (letters));
if (!buf)
return (0);

rd = read(fd, buf, letters);
wt = write(STDOUT_FILENO, buf, rd);

close(fd);
free(buf);

return (wt);
}
