#include <stdio.h>

/**
 *main- Entry point
 *@void: Null value
 *Description: prints all possible combinations of single-digit numbers.
 *Return: Zero value
 */

int main(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		putchar(i);
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);

}
