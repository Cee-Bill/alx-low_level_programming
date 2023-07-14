#include <stdio.h>
/**
 * main- prints the alphabet in lowercase, and then in uppercase
 * Return: returns 0 for success
 */
int main(void)
{
	char alphabet;
	char alphABET;

	for  (alphabet = 'a'; alphabet <= 'z'; alphabet++)
	{
		putchar(alphabet);
	}

	for (alphABET = 'A'; alphABET <= 'Z'; alphABET++)
		putchar(alphABET);
	putchar('\n');
	return (0);
}
