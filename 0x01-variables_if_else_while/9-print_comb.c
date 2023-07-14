#include <stdio.h>
/**
 * main- prints all possible combinations of single-digit numbers
 * Return: returns 0 for success
 */
int main(void)
{
	int num;

	for (num = 0; num <= 9; num++)
	{
		putchar(num + '0');
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
