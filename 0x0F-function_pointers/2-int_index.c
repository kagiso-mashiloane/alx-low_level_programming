#include "function_pointers.h"

/**
 * int_index - (int *array, int size, int (*cmp)(int));
 * @array: the value of numbers
 *  @size:  the number of elements in the array array
 *  @cmp:pointer to the function to be used to compare values
 *  Return: Return -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			while (i < size)
			{
				if (cmp(array[i]))
					return (i);

				i++;
			}
		}
	}

	return (-1);
}
