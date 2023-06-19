#include <stdio.h>
/**
 *  *main-Entry point
 *   *@void:Null value
 *    *Description:Print alphabet lowercase and uppercase
 *     *Return:Always 0(sucess)
 */
int main(void)
{
	int i = 97;
	int k = 65;

	while (i <= 122)
	{
		putchar(i);
		i++;
	}
	while (k <= 90)
	{
		putchar(k);
		k++;
	}
	putchar('\n');
	return (0);
}
