#include <stdlib.h>
#include "main.h"

/**
 * multiply - Multiplies two positive numbers
 * @num1: First number
 * @num2: Second number
 *
 * Return: 0 on success
 */
int multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, carry;
	int *result;
	int res_size;

	while (num1[len1] != '\0')
		len1++;
	while (num2[len2] != '\0')
		len2++;
	
	res_size = len1 + len2;
	result = malloc(res_size * sizeof(int));
	if (result == NULL)
		return (-1);

	for (i = 0; i < res_size; i++)
		result[i] = 0;
	
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			int digit1 = num1[i] - '0';
			int digit2 = num2[j] - '0';
			int sum = digit1 * digit2 + result[i + j + 1] + carry;
			result[i + j + 1] = sum % 10;
			carry = sum / 10;
		}
		result[i] += carry;
	}
	
	i = 0;
	while (i < res_size - 1 && result[i] == 0)
		i++;
	
	for (; i < res_size; i++)
		_putchar(result[i] + '0');
	_putchar('\n');
	
	free(result);
	
	return (0);
}

int main(int argc, char *argv[])
{
	char *num1;
	char *num2;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	multiply(num1, num2);

	return (0);
}
