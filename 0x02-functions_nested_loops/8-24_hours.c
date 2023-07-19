#include "main.h"
/**
 * jack_bauer - prints every minute of the day
 * Return: void
 */
void jack_bauer(void)
{
	int i;
	int j;
	int a;
	int b;

	for (a = 0; a <= 2; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			for (i = 0; i <= 5; i++)
			{
				for (j = 0; j <= 9; j++)
				{
					if (a >= 2 && b >= 4)
						break;

					_putchar(a + '0');
					_putchar(b + '0');
					_putchar(':');
					_putchar(i + '0');
					_putchar(j + '0');
					_putchar('\n');
				}
			}
		}
	}
}
