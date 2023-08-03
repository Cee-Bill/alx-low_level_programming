#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: integer | number to evaluated
 * @y: integer | the power
 * Return: integer of the evaluated raised number
 */

int _pow_recursion(int x, int y)
{
	if ((x == 1) || (y == 0))
	{
		return (1);
	}

	if (y < 0)
	{
		return (-1);
	}

	return (x * (_pow_recursion(x, y - 1)));
}
