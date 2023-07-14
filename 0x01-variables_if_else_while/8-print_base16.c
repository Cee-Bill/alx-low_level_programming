#include <stdio.h>
/**
* main- prints all the numbers of base 16 in lowercase
* Return: returns 0 for success
*/
int main(void)
{
	int n;
	int i;

	for (n = 0; n <= 9; n++)
		putchar(n + '0');
	for (i = 'a'; i <= 'f'; i++)
		putchar(i);

	putchar('\n');
	return (0);
}
