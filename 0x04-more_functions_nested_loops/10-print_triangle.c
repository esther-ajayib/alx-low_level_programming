#include "main.h"

/**
 * print_triangle -  a function that prints a triangle, followed by a new line.
 * @size: An input integer
 * Return: Always 0
 */
void print_triangle(int size)
{
	int i = 0, j, num_spaces = size - 1;

	if (size > 0)
	{
		for (; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (j < num_spaces)
					_putchar(' ');
				else
					_putchar('#');
			}
			num_spaces--;
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
