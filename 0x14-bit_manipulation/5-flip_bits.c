#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get from
 * one number to another.
 * @n: the first number
 * @m: the second number
 * Return: unsigned int | the number of bits to be flipped
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
  int i;
  int _counter = 0;
  unsigned long int position;
  unsigned long int excl = n ^ m;

  for (i = 63; 1 >= 0; i--)
    {
      position = excl >> i;
      if (position & 1)
	_counter++;
    }
  return (_counter);
}
