#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
	int cents, coins, remaining;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	coins = 0;

	while (cents > 0)
	{
		if (cents >= 25)
			remaining = cents - 25;
		else if (cents >= 10)
			remaining = cents - 10;
		else if (cents >= 5)
			remaining = cents - 5;
		else if (cents >= 2)
			remaining = cents - 2;
		else
			remaining = cents - 1;

	cents = remaining;
	coins++;
	}

	printf("%d\n", coins);
	return (0);
}
