#include<stdio.h>
/**
* main- prints all single digit numbers of base 10 starting from 0
* Return: return 0 for success
*/
int main(void)
{
	int digits;

	digits = 0;

	while (digits < 10)
	{
		putchar(digits + '0');
		digits++;
	}
	putchar('\n');
	return (0);
}
