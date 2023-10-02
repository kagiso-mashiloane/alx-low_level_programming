#include "main.h"
/**
 * create_file - function that creates a file.
 * @filename: 1-create_file
 * @text_content: if filename is NULL return -1
 * if text_content is NULL create an empty file
 * Return:  1 on success, -1 on failure (file can not
 * be created, file can not be written, write “fails”, etc…)
 */
int create_file(const char *filename, char *text_content)
{
	int k, i, buff;

	if (filename == NULL)
		return (-1);
	k = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (k == -1)
		return (-1);
	if (text_content)
	{
		for (i = 0; text_content[i] != '\0'; i++)
			;
		buff = write(k, text_content, i);
		if (buff == -1)
			return (-1);
	}
	close(k);
	return (1);
}
