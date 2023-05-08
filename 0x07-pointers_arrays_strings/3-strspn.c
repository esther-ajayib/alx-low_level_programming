#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: Pointer to the string to search
 * @accept: Pointer to the string containing the bytes to match
 *
 * Return: The number of bytes in the initial segment of s that consist only
 *         of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int is_match;
	unsigned int i;

	while (*s)
	{
		is_match = 0;

		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				count++;
				is_match = 1;
				break;
			}
		}

		if (is_match == 0)
			break;

		s++;
	}

	return (count);
}
