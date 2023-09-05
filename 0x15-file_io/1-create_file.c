#include "main.h"

/**
 * create_file - creates a file and write text content to it
 * @filename: name of the file to create
 * @text_content: content to be written to the file (NULL-terminated string)
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
int fd, num_letters, rwt;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

if (fd == -1)
return (-1);

if (!text_content)
text_content = "";

for (num_letters = 0; text_content[num_letters]; num_letters++);

rwt = write(fd, text_content, num_letters);

if (rwt == -1)
{
close(fd);
return (-1);
}

close(fd);
return (1);
}
