#include <stdio.h>
/**
* main- print all alphabets except q and e
* Return: returns 0 for sucess
*/
int main(void)
{
	char alphabet;

	for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
	{
		if ((alphabet == 'q') | (alphabet == 'e'))
			continue;
		putchar(alphabet);
	}
	putchar('\n');
	return (0);
}
