#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Finds and prints the sum of even-valued terms in the Fibonacci sequence
 *              whose values do not exceed 4,000,000
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int i;
	long int prev1 = 1, prev2 = 2, curr;
	long int sum = 0;

	while (prev1 <= 4000000)
	{
		if (prev1 % 2 == 0)
			sum += prev1;
		
		curr = prev1 + prev2;
		prev1 = prev2;
		prev2 = curr;
	}

	printf("%ld\n", sum);

	return (0);
}
