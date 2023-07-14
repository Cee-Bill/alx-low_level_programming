#include <stdio.h>
#include <ctype.h>
/**
 * main- prints the alphabet in lowercase
 * Return: returns 0 for success
*/
int main(void)
{
	char alphabet = 'a';

	while (alphabet <= 'z')
	{
		putchar(alphabet);
		alphabet++;
	}
	putchar('\n');
	return (0);
}
