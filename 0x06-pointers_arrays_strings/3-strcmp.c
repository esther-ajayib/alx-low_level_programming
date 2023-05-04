#include "main.h"

/**
 * _strcmp - Compares two strings.
 *
 * @s1: Pointer to the first string to be compared.
 * @s2: Pointer to the second string to be compared.
 *
 * Return: 0 if both strings are equal,
 *         a negative value if s1 is less than s2,
 *         or a positive value if s1 is greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

	return (s1[i] - s2[i]);
}
