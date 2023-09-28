#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: unsigned long int | number to search
 * @index: bit index
 * Return: value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int result;

	if (index > 63)
		return (-1);

	result = (n >> index) & 1;
	return (result);
}
