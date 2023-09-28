#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the unsigned long int whose bit needs to be set.
 * @bit_index: The index of the bit to be set, starting from 0.
 *
 * Return: 1 if successful, -1 on error.
 */
int set_bit(unsigned long int *n, unsigned int bit_index)
{
if (bit_index >= sizeof(unsigned long int) * 8) /* Ensure valid index */
return (-1);

*n |= (1 << bit_index); /* Set the bit at the given index */

return (1);
}
