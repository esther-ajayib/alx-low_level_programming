#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 61

/**
 * main - Generates a random valid password for 101-crackme program
 *
 * Return: 0 on success
 */
int main(void)
{
	char password[PASSWORD_LENGTH + 1];
	int i, sum, diff, rand_num;

	srand(time(NULL));

	for (i = 0; i < 9; i++)
	{
		password[i] = rand() % 26 + 'A';
	}

	for (; i < 18; i++)
	{
		password[i] = rand() % 26 + 'a';
	}

	for (; i < 23; i++)
	{
	    password[i] = rand() % 10 + '0';
	}

	password[i++] = '!';
	password[i++] = '@';
	password[i++] = '#';
	password[i++] = '$';
	password[i++] = '%';
	password[i++] = '^';

	sum = 0;
	for (; i < PASSWORD_LENGTH; i++)
	{
		rand_num = rand() % 3;
		diff = rand() % (sum + 3) + 1;
		sum += diff;
		if (rand_num == 0)
		{
			password[i] = diff + '0';
		}
		else if (rand_num == 1)
		{
			password[i] = diff + 'A';
		}
		else
		{
			password[i] = diff + 'a';
		}
	}

	password[PASSWORD_LENGTH] = '\0';
	printf("%s", password);

	return (0);
}
