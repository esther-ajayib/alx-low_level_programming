#include <stdio.h>

/**
 * main - Prints all numbers of base 16 in lowercase followed by a new line
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char hexadecimal;

	for (hexadecimal = '0'; hexadecimal <= '9'; hexadecimal++)
		putchar(hexadecimal);
	for (hexadecimal = 'a'; hexadecimal <= 'f'; hexadecimal++)
		putchar(hexadecimal);
	putchar('\n');

	return (0);
}
