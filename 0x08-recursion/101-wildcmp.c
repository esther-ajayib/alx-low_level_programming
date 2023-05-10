#include "main.h"

/**
 * wildcmp_recursive - Helper function to compare two strings with wildcard pattern recursively.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 1 if strings are identical, 0 otherwise.
 */
int wildcmp_recursive(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp_recursive(s1, s2 + 1));
		else if (*(s2 + 1) == '\0')
			return (1);
		else if (*s1 == '\0')
			return (0);
		else
			return (wildcmp_recursive(s1, s2 + 1) || wildcmp_recursive(s1 + 1, s2));
	}
	else if (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (1);
		else
			return (wildcmp_recursive(s1 + 1, s2 + 1));
	}

	return (0);
}

/**
 * wildcmp - Compares two strings and checks if they can be considered identical.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 1 if strings are identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	return (wildcmp_recursive(s1, s2));
}
