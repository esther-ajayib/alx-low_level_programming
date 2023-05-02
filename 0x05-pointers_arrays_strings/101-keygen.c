
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 15

/**
 * main - Generates a random valid password for 101-crackme program
 *
 * Return: 0 on success
 */
int main(void)
{
	char password[PASSWORD_LENGTH + 1];
	int i, rand_num;

	srand(time(NULL));

	for (i = 0; i < 3; i++)
	{
		password[i] = rand() % 26 + 'A';
	}
	
	for (; i < 6; i++)
	{
		password[i] = rand() % 26 + 'a';
	}

	for (; i < 8; i++)
	{
		password[i] = rand() % 10 + '0';
	}

	password[i++] = '!';
	password[i++] = '@';

	for (; i < PASSWORD_LENGTH; i++)
	{
		rand_num = rand() % 2;
		if (rand_num == 0)
			password[i] = rand() % 26 + 'A';
		else
		password[i] = rand() % 26 + 'a';
	}

	password[PASSWORD_LENGTH] = '\0';
	printf("%s", password);

	return (0);
}
