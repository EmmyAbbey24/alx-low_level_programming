#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
unsigned int i_end = 1;
char *c = (char *) &i_end;

return (*c);
}
