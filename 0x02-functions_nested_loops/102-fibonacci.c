#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the first 50 Fibonacci numbers separated by , and space
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int i;
	long int fibonacci[50];

	fibonacci[0] = 1;
	fibonacci[1] = 2;
	printf("%ld, %ld, ", fibonacci[0], fibonacci[1]);

	for (i = 2; i < 49; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		printf("%ld, ", fibonacci[i]);
	}

	fibonacci[49] = fibonacci[48] + fibonacci[47];
	printf("%ld\n", fibonacci[49]);

	return (0);
}
