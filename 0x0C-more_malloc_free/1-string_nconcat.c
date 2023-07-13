#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * @n: amount of bytes.
 * Return: pointer to the allocated memory.
 * if malloc fails, status value is equal to 98.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s3;
	unsigned int ls1, ls2, ls3, i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (ls1 = 0; s1[ls1] != '\0'; ls1++)
		;

	for (ls2 = 0; s2[ls2] != '\0'; ls2++)
		;

	if (n > ls2)
		n = ls2;

	ls3 = ls1 + n;

	s3 = malloc(ls3 + 1);

	if (s3 == NULL)
		return (NULL);

	for (i = 0; i < ls3; i++)
		if (i < ls1)
			s3[i] = s1[i];
		else
			s3[i] = s2[i - ls1];

	s3[i] = '\0';

	return (s3);
}

