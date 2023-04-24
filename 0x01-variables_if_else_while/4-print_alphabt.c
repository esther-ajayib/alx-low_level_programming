#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
        char lowercase;

        for (lowercase = 'a'; lowercase <= 'z'; lowercase++)
	{
		if (lowercase != 'e' && lowercase != 'q')
			putchar(lowercase);
	}
        putchar('\n');

        return (0);
}
