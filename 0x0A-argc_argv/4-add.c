#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 if successful, 1 if error
 */
int main(int argc, char **argv)
{
	int num, result = 0, i;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		for (num = 0; argv[i][num]; num++)
		{
			if (!isdigit(argv[i][num]))
			{
				printf("Error\n");
				return (1);
			}
		}

		num = atoi(argv[i]);
		result += num;
	}

	printf("%d\n", result);
	return (0);
}
