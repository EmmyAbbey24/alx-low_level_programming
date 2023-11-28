#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @file: Pointer to the file name.
 * @text: The string to append.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *file, char *text)
{
	int fd, wr, length = 0;

	if (file == NULL)
		return (-1);

	if (text != NULL)
	{
		while (text[length])
			length++;
	}

	fd = open(file, O_WRONLY | O_APPEND);
	wr = write(fd, text, length);

	if (fd == -1 || wr == -1)
		return (-1);

	close(fd);

	return (1);
}
