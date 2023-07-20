#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * op_add - should return a pointer to the function(+)
 * @a: variables
 * @b: variables
 * Return: Answer
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub -should return a pointer to the function(-)
 * @a:variables
 * @b: variables
 * Return: Answer
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - should return a pointer to the function(*)
 * @a: variables
 * @b: variables
 *  Return: Answer
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - should return a pointer to the function(/)
 * @a: variables
 * @b: variables
 *  Return: Answer
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
 * op_mod - should return a pointer to the function(%)
 * @a: variables
 * @b: variables
 * Return: Answer
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
