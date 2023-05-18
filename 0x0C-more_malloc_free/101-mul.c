#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * multiply - Multiplies two positive numbers
 * @num1: The first number
 * @num2: The second number
 *
 * Return: Always 0
 */
int multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, k, carry, n1, n2, sum, *result;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	result = malloc(sizeof(int) * (len1 + len2));
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}

		if (carry > 0)
			result[i + j + 1] += carry;
	}

	k = 0;
	while (result[k] == 0 && k < len1 + len2)
		k++;

	if (k == len1 + len2)
		_putchar('0');

	for (; k < len1 + len2; k++)
		_putchar(result[k] + '0');

	_putchar('\n');

	free(result);
	return (0);
}

/**
 * main - Entry point
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (98);
			}
		}
	}

	multiply(argv[1], argv[2]);

	return (0);
}
