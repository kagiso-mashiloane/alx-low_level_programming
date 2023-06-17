#include <stdio.h>
/**
 * main- Entry point
 * @void: Null value
 * Description: Print alphabet lowercase
 * Return: Zero value
 */
int main(void)
{
	char alp[26] = "abcdefghigklmnopqrstuvwxyz";
	int i;

	for (i = 0; i < 26; i++)
	{
		putchar(alp[i]);
	}
	putchar('\n');
	return (0);
}
