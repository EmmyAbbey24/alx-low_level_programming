#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 * @binary: Pointer to a binary string (0s and 1s).
 *
 * Return: The converted unsigned integer, or 0 if there's an error.
 */
unsigned int binary_to_uint(const char *binary)
{
unsigned int conv_int = 0;
int i = 0;

if (binary == NULL)
return (0);

while (binary[i] != '\0')
{
if (binary[i] != '0' && binary[i] != '1')
return (0);

conv_int = (conv_int << 1) + (binary[i] - '0');
i++;
}

return (conv_int);
}

