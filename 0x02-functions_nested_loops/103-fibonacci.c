#include <unistd.h>

void print_int(int n)
{
	char buf[20];
	int i = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return;
	}

	while (n > 0)
	{
		buf[i++] = '0' + (n % 10);
		n /= 10;
	}

	for (i--; i >= 0; i--)
		write(1, &buf[i], 1);
}

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
	write(1, "\n", 1);

	return (0);
}
