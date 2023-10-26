#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to,
 * flip to get from one number to another.
 * @n: number of another
 * @m: number of another
 * Return: the number of bits you would need to flip,
 * to get from one number to another.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int i = 0;
	unsigned long int xor_value = n ^ m;

	while (xor_value)
	{
		i++;
		xor_value &= xor_value - 1;
	}
	return (i);
}
