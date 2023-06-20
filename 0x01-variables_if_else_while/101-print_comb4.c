#include <stdio.h>
/**
 *  main- Entry point
 * @void: Null value*
 * Description: 'Print The three digits must be different 012, 120, 102 '
 * Return: Zero value
 */
int main(void)
{
	int i = 0;
	int j, k;
	int count = 0;

	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				putchar(i + '0');
				putchar(j + '0');
				putchar(k + '0');
				if (count != 119)
				{
					putchar(',');
					putchar(' ');
				}
				k++;
				count++;
			}
			j++;
		}
		i++;
	}
	putchar('\n');
	return (0);
}
