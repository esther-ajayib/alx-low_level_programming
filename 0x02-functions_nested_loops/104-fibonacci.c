#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 */

void print_number(int n)
{
	if (n < 0) {
	_putchar('-');
		n = -n;
	}

	if (n / 10)
		print_number(n / 10);

	_putchar(n % 10 + '0');
}

/**
 * main - prints the first 98 Fibonacci numbers
 *
 * Return: 0 (Success)
 */
int main(void)
{
	unsigned long int i, num1 = 1, num2 = 2, sum;

	print_number(num1);
	_putchar(',');
	_putchar(' ');

	print_number(num2);
	_putchar(',');

	for (i = 0; i < 96; i++) {
		sum = num1 + num2;
		_putchar(' ');

		print_number(sum);

		if (i != 95)
			_putchar(',');

		num1 = num2;
		num2 = sum;
	}

	_putchar('\n');
	return (0);
}
