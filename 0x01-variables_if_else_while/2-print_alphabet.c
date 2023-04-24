#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Prints the lowercase alphabet using only putchar function
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char lowercase;

	for (lowercase = 'a'; lowercase <= 'z'; lowercase++) 
	{
		putchar(lowercase);
	}
	
	putchar('\n');
	
	return (0);
}
