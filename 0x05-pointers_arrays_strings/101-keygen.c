#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int i, sum, diff, c;
	char password[84];

	srand(time(NULL));

	for (i = 0, sum = 0; sum < 2772 - 122; i++)
	{
		c = rand() % 62;
		if (c < 10)
			password[i] = '0' + c;
		else if (c < 36)
			password[i] = 'a' + c - 10;
		else
			password[i] = 'A' + c - 36;
		sum += password[i];
	}

	diff = 2772 - sum;
	password[i] = diff % 10 + '0';
	password[i + 1] = '\0';

	printf("%s\n", password);
	return (0);
}

