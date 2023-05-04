#include <stdio.h>
#include "main.h"

/**
 * print_buffer - Prints the content of a buffer
 * @b: The buffer to print
 * @size: The size of the buffer
 *
 * Return: void
 */

void print_buffer(char *b, int size)
{
	int i, j;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = i; j < i + 10; j++)
		{
			if (j < size)
			{
				printf("%02x", b[j]);
			} else
			{
				printf("  ");
			}

			if (j % 2 != 0)
			{
				printf(" ");
			}
		}

		for (j = i; j < i + 10; j++)
		{
			if (j >= size)
			{
				break;
			}
			else if (*(b + j) >= ' ' && *(b + j) <= '~')
			{
				printf("%c", *(b + j));
			}
			else
			{
				printf(".");
			}
		}

		printf("\n");
	}
}

