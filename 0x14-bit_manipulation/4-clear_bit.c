#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the unsigned long int whose bit needs to be cleared.
 * @i: The index of the bit to be cleared, starting from 0.
 *
 * Return: 1 if successful, -1 on error.
 */
int clear_bit(unsigned long int *n, unsigned int i)
{
if (i >= sizeof(unsigned long int) * 8)
return (-1);

*n &= ~(1 << i);

return (1);
}
