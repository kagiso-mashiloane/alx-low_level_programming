#include <stdio.h>
/**
 * main - C program that prints the size of various types
 * Code by Prince Solomon
 * Return: 0
*/
int main(void)
{
	
	printf("size of a char: %lu byte(s)\n", sizeof(char));
	printf("size of a int: %lu byte(s)\n", sizeof(int));
	printf("size of a long int: %lu byte(s)\n",  sizeof(long int));
	printf("size of a lolng lolng int: %lu byte(s)\n", sizeof(long long int));
	printf("size of a float: %lu byte(s)\n", sizeof(float));
	return (0);
}
