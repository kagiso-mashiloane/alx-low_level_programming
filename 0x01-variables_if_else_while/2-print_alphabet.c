#include <stdio.h>
/**
 *main-Entry point
 *@void:Null value
 *Description:Print alphabet lowercase
 *Return:Always 0(sucess)
 */
int main(void)
{
	char i = 'a';

	while (i <= 'z')
	{
	putchar(i);
	i++;
	}
	putchar('\n');
	return (0);
}
