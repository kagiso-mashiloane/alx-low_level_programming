#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/*checker 97*/
/**
* checker97 - number of argument is not the correct one,
* exit with code 97 and print Usage: cp file_from file_to
* @argc:  already exists, truncate it
* Return:return void
*/
void checker97(int argc)
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
}
/*checker 98*/
/**
* checker98 - does not exist, or if you can not read it,
* exit with code 98 and print Error: Can't read from file NAME_OF_THE_FILE
* @file: cp
* @checker: checks if the first argument passed to your program
* @buff_from:  file_from, or -1
* @buff_to: file_to, or -1
* Return:return void
*/
void checker98(ssize_t checker, char *file, int buff_from, int buff_to)
{
if (checker == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
if (buff_from != -1)
close(buff_from);
if (buff_to != -1)
close(buff_to);
exit(98);
}
}
/*checker 99 */
/**
* checker99 - checks that file_to was created and/or can be written to
* @checker: checks if the second argument passed to your program
* @file: cp
* @buff_from:  file_from, or -1
* @buff_to: file_to, or -1
* Return: return void
*/
void checker99(ssize_t checker, char *file, int buff_from, int buff_to)
{
if (checker == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
if (buff_from != -1)
close(buff_from);
if (buff_to != -1)
close(buff_to);
exit(99);
}
}
/*checker 100*/
/**
* checker100 - close a file descriptor , exit with code 100 and,
* print Error: Can't close fd FD_VALUE
* @checker: checks if true or false
* @fd: file descriptor
* Return:return void
*/
void checker100(int checker, int fd)
{
if (checker == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}
/*checker main*/
/**
* main - Copies the content of a file to another file.
* @argc: number of arguments passed
* @argv: pointers to the arguments
* Return: return 0 on success
*/
int main(int argc, char *argv[])
{
char buffer[1024];
ssize_t buffr, buffrw;
mode_t file_perm;
int buff_from, buff_to, close_to, close_from;

checker97(argc);
buff_from = open(argv[1], O_RDONLY);
checker98((ssize_t)buff_from, argv[1], -1, -1);
file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
buff_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
checker99((ssize_t)buff_to, argv[2], buff_from, -1);
buffr = 1024;
while (buffr == 1024)
{
buffr = read(buff_from, buffer, 1024);
checker98(buffr, argv[1], buff_from, buff_to);
buffrw = write(buff_to, buffer, buffr);
if (buffrw != buffr)
buffrw = -1;
checker99(buffrw, argv[2], buff_from, buff_to);
}
close_to = close(buff_to);
close_from = close(buff_from);
checker100(close_to, buff_to);
checker100(close_from, buff_from);
return (0);
}
