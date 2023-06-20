#include <stdio.h>
/**
 *main- Entry point
 *@void: Null value
 *Description: 'prints all possible combinations of single-digit numbers.'
 *Return: Zero value
 */
int main(void)
{
	int n;

	for (n = 48; n <= 57; n++)
	{
		putchar(n);
		if (n == 57)
		{
			n++;
			continue;
		}
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);

}
