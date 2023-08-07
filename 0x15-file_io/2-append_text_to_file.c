#include "main.h"
/**
 * append_text_to_file -  that appends text at the end of a file.
 * @filename: 2-append_text_to_file
 * @text_content: is the NULL terminated string to,
 * add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int k, i, len;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		return (1);
	k = open(filename, O_APPEND | O_WRONLY);
	if (k == -1)
		return (-1);
	for (i = 0; text_content[i] != '\0'; i++)
		;
	len = write(k, text_content, i);
	if (len == -1)
		return (-1);
	close(k);
	return (1);
}
