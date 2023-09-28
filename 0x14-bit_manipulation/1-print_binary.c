#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the decimal number to be converted
 * Return: void
 */

void print_binary(unsigned long int n)
{
  int i;
  int num = 0;
  unsigned long int position;

  for (i = 63; i >= 0; i--)
    {
      position = n >> i;

      if (position & 1)
	_putchar('1'), num++;

      else if (num)
	_putchar('0');
    }
  if (!num)
    _putchar('0');
}
