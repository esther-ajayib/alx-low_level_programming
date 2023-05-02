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
	char password[84];
	int i, sum = 0, diff_half1, diff_half2;
	char *str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		password[i] = str[rand() % 62];
	}

	for (i = 0; i < 10; i++)
	{
		sum += password[i];
	}

	diff_half1 = (sum - '0') / 2;
	diff_half2 = (sum - '0') - diff_half1;

	for (i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			password[i] += diff_half1;
		else
			password[i] -= diff_half2;
	}

	password[10] = '\0';

	printf("%s", password);

	return (0);
}
