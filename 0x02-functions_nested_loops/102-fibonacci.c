#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the first 50 Fibonacci numbers separated by comma and space
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

	for (i = 2; i < 49; i++) /* Loop to generate and print the next 48 Fibonacci numbers */
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		printf("%ld, ", fibonacci[i]); /* Print the calculated Fibonacci number followed by comma and space */
	}

	fibonacci[49] = fibonacci[48] + fibonacci[47];
	printf("%ld\n", fibonacci[49]); /* Print the last Fibonacci number followed by a newline */

	return 0;
}
