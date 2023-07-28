#include <stdio.h>

/**
 * hareTortoise  - Prints a string before the
 * main function is executed.
 */
void __attribute__((constructor)) hareTortoise(void)
{
printf("You're beat! and yet, you must allow,\n"
	       "I bore my house upon my back!\n");
}
