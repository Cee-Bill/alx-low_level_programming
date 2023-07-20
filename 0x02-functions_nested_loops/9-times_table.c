#include "main.h"
/**
 * times_table - prints the 9 times table
 * Return: void
 */

void times_table(void)
{
	int a, b, retval, i, j;

	for (a = 0; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			retval = a * b;

			if (retval == 0 && b == 0)
			{
				_putchar(retval + '0');
			}

			_putchar(44);
			_putchar(32);

			if (retval <= 9)
			{
				_putchar(' ');
				_putchar(retval + '0');
			}

			if (retval > 9)
			{
				i = retval / 10;
				j = retval % 10;

				_putchar(i + '0');
				_putchar(j + '0');
			}
		}
		_putchar('\n');
	}
}
