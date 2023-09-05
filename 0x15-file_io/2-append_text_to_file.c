#include "main.h"

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: name of the file
 * @text_content: content to append to the file (NULL-terminated string)
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fd, num_letters, rwt;

if (!filename)
return (-1);

if (!text_content)
return (1);

fd = open(filename, O_WRONLY | O_APPEND);

if (fd == -1)
return (-1);

for (num_letters = 0; text_content[num_letters]; num_letters++)
;

rwt = write(fd, text_content, num_letters);

if (rwt == -1)
{
close(fd);
return (-1);
}

close(fd);
return (1);
}
