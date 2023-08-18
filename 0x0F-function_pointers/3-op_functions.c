#include "3-calc.h"

/**
 * op_add - sum of two intger params
 * @a: integer param 1
 * @b: integer param 2
 *
 * Return: the integer sum of a and b
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - difference of two intger params
 * @a: integer param 1
 * @b: integer param 2
 * Return: the integer difference of a and b
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - product of two intger params
 * @a: integer param 1
 * @b: integer param 2
 * Return: the product of a and b
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - division of two intger params
 * @a: integer param 1
 * @b: integer param 2
 * Return: the result of the division of a by b
 */

int op_div(int a, int b)
{
	return (a / b);
}


/**
 * op_mod - remainder of the division of a by b
 * @a: integer param 1
 * @b: integer param 2
 * Return: the result of the remainder of the division of a by b
 */

int op_mod(int a, int b)
{
	return (a % b);
}
