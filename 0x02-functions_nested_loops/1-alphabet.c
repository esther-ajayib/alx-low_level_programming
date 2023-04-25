#include "main.h"

/**
 * print_alphabet - prints the lowercase alphabet
 */
void print_alphabet(void)
{
	int i;
	char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";

	for (i = 0; i < 26; i++)
	{
		_putchar(alphabet[i]);
	}

	_putchar('\n');
}
