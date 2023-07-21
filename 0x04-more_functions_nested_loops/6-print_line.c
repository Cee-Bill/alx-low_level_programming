#include "main.h"
/**
 * print_line - draws a straight line in the terminal
 * @n: expected integer
 */
void print_line(int n)
{
	if (n > 0)
	{
		int i;

		for (i = 0; i <= n; i++)
		{
			_putchar('_');
		}
	}
	_putchar('\n');
}
