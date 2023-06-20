#include <stdio.h>
/**
 * main- Entry point
 * @void: Null value
 * Description: 'Print numbers shoud range from 0 to 99'
 * Return: Zero value
 */
int main(void)
{
	int i = 0;
	int j;
	int k;

	int ii;
	int jj;
	int kk;

	while (i <= 98)
	{
		j = (i / 10 + '0');
		k = (i % 10 + '0');
		ii = 0;
		while (ii <= 99)
		{
			jj = (ii / 10 + '0');
			kk = (ii % 10 + '0');

			if (i < ii)
			{
				putchar(j);
				putchar(k);
				putchar(' ');
				putchar(jj);
				putchar(kk);
				if (i != 98)
				{
					putchar(',');
					putchar(' ');
				}
			}
			ii++;
		}
		i++;
	}
	putchar('\n');
	return (0);
}
