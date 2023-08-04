#include "main.h"
#include <stdio.h>

/**
 * sqrt_ - return natural square root of a number
 * @b: num,ber to be evaluated
 * @i: counter
 * Return: square root of a number
 */

int sqrt_(int i, int b)
{
	if (b * b == i)
	{
		return (b);
	}
	else if (b * b > i)
	{
		return (-1);
	}
	return (sqrt_(i, b + 1));
}

/**
 * _sqrt_recursion - natural square root of a number
 * @n: num,ber to be evaluated
 * Return: integer- the natural square root of a number
 */


int _sqrt_recursion(int n)
{
	return (sqrt_(n, 0));
}
