#include <stdio.h>
/**
 * main- Entry point
 * @void: Null value
 * Description: 'Print numbers shoud range from 0 to 99'
 * Return: Zero value
 */
int main(void)
{
	int i, j, k, l;
	int count, count1;

	for (count = 0; count <= 99; count++)
	{
		i = count / 10;
		j = count % 10;
		for (count1 = 0; count1 <= 99; count++)
		{
		k = count1 / 10;
		l = count1 % 10;

		if (i < k || (i == k && j < l))
		{
			putchar(i + '0');
			putchar(j + '0');
			putchar(' ');
			putchar(k + '0');
			putchar(l + '0');
			if (!(i == 9 && j == 8))
			{
				putchar(',');
				putchar(' ');
			}
		}
		}
	}
	putchar('\n');
	return (0);
}
