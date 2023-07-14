#include <stdio.h>
/**
* main- prints the lowercase alphabet in reverse
* Return: returns 0 for success
*/
int main(void)
{
	char reverse_alpha;

	reverse_alpha = 'z';

	while (reverse_alpha >= 'a')
	{
		putchar(reverse_alpha);
		reverse_alpha--;
	}
	putchar('\n');
	return (0);
}
