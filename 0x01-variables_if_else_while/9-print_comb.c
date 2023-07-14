#include <stdio.h>
/**
 * main- prints all possible combinations of single-digit numbers
 * Return: returns 0 for success
 */
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
	{
		putchar(num + '0');

		if (num == 9)
		{
			continue;
			putchar(num + '0');
		}

		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
