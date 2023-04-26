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
	int i;
	unsigned long int prev1 = 1, prev2 = 2, curr;

	printf("%d, %d, ", prev1, prev2);

	for (i = 3; i <= 98; i++)
	{
		curr = prev1 + prev2;
		prev1 = prev2;
		prev2 = curr;

		if (i == 98)
			printf("%lu\n", curr);
		else
			printf("%lu, ", curr);
	}

	return (0);
}
