#include "main.h"

/* clear_bit - sets the value of a bit to 0 at a given index
 * @n: the n umber to be searched
 * @index: the bit index
 * Return: 1 if successful and -1 if failed
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
  if (index > 63)
    return (-1);

  *n = (~(1UL << index) & *n);
  return (1);
}
