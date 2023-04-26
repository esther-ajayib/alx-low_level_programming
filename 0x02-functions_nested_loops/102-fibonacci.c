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
	int num1 = 1, num2 = 2, i, sum;
	int count = 0;

	printf("%d, %d", num1, num2);

	for (i = 0; i < 48; i++)
	{
		sum = num1 + num2;
		printf(", %d", sum);
		num1 = num2;
		num2 = sum;
	}

	printf("\n"),

	return (0);
}
