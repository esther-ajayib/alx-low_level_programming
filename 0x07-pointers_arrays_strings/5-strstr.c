#include "main.h"
#include <stddef.h>

/**
 * _strstr - Locates a substring
 * @haystack: Pointer to the string to search within
 * @needle: Pointer to the substring to locate
 *
 * Return: Pointer to the beginning of the located substring,
 *         or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	if (*needle == '\0')
		return haystack;

	while (*haystack)
	{
		char *h = haystack;
		char *n = needle;

		while (*h && *n && *h == *n)
		{
			h++;
			n++;
		}

		if (*n == '\0')
			return (haystack);

		haystack++;
	}

	return (NULL);
}
