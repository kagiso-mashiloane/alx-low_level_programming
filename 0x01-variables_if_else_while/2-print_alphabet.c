#include <stdio.h>
#include <string.h>
/**
 * main- Entry point
 * @void: Null value
 * Description: Print alphabet lowercase
 * Return: Zero value
 */
int main(void)
{
	char i;

	for (i = 'a';i <='z';i++)
		putchar(i);
	putchar('\n');
	return (0);
}
