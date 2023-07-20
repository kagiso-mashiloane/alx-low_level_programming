#include "3-calc.h"
#include <stdlib.h>
#include <string.h>

/**
 * get_op_func -  should return a pointer to the function op_add
 * @s:  does not match any of the 5 expected operators
 *(+, -, *, /, %), return NULL
 * Return:Return 0
 */

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
	{ "+", op_add },
	{ "-", op_sub },
	{ "*", op_mul },
	{ "/", op_div },
	{ "%", op_mod },
	{ NULL, NULL }
	};
	int i = 0;

	while (i < 5)
	{
		if (strcmp(s, ops[i].op) == 0)
			return (ops[i].f);
		i++;
	}

	return (0);
}
