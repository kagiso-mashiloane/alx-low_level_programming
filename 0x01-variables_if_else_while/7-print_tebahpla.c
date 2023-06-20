#include <stdio.h>
/**
 *  *main-Entry point
 *   *@void:Null value
 *    *Description:Print lowercase alphabet in reverse
 *     *Return:Always 0(sucess)
 */
int main(void)
{
	int i = 122;

	while (i >= 97)
	{
		putchar(i);
		i--;
	}
	putchar('\n');
	return (0);
}
