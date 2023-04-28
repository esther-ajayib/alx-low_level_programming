#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Finds and prints the first 98 Fibonacci numbers
 *              separated by comma and space, followed by a newline
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int i, a = 1, b = 2, c;

	printf("%d, %d", a, b);

	for (i = 3; i <= 98; i++)
	{
		c = a + b;
		printf(", %d", c);
		a = b;
		b = c;
	}
	
	printf("\n");

	return (0);
