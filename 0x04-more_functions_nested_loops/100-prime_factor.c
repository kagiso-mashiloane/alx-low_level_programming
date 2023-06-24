#include "stdio.h"
/**
 * main - largest prime factor of 612852475143
 * Description:The prime factors of 1231952 are 2, 2, 2, 2, 37 and 2081.
 * Return: 0
 */
int main(void)
{
	long int x, i, k;

	k = -1;
	x = 612852475143;

	while (x % 2 == 0)
	{
		k = 2;
		x = x / 2;
	}
	for (i = 3; i <= x / 2; i = i + 2)
	{
		while (x % i == 0)
		{
			k = i;
			x = x / i;
		}
	}
	if (x > 2)
		k = x;
	printf("%ld\n", k);
	return (0);
}
