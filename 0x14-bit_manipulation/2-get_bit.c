#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: The unsigned long int to extract the bit from.
 * @i: The index of the bit to be extracted, starting from 0.
 *
 * Return: The value of the bit at index or -1 on error.
 */
int get_bit(unsigned long int n, unsigned int i)
{
if (i >= sizeof(unsigned long int) * 8) /* Ensure valid index */
return (-1);

return ((n >> i) & 1); /* Get the bit at the given index */
}
