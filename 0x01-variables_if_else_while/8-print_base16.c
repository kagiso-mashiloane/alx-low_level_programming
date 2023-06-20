#include <stdio.h>

/**
 *main- Entry point
 *@void: Null value
 *Description: Prints all the numbers of base 16 in lowercase
 *Return: Zero value
 */

int main(void)
{
	int i;
	int k;

	for (i = 48; i <= 57; i++)
	{
		putchar(i);
	}
	for (k = 97; k <= 102; k++)
	{
		putchar(k);
	}
	putchar('\n');
	return (0);
}
