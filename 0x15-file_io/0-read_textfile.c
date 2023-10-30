#include "main.h"
/**
 * read_textfile - that reads a text file and,
 * prints it to the POSIX standard output.
 * @filename:0-read_textfile
 * @letters: is the number of letters it should read and print
 * Return: actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t buffr, buffwr;
	int k;

	if (filename == NULL)
		return (0);
	k = open(filename, O_RDONLY);
	if (k == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(k);
		return (0);
	}
	buffr = read(k, buffer, letters);
	close(k);
	if (buffr == -1)
	{
		free(buffer);
		return (0);
	}
	buffwr = write(STDOUT_FILENO, buffer, buffr);
	free(buffer);

	if (buffr != buffwr)
		return (0);
	return (buffwr);
}
