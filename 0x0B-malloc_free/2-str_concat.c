#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Pointer to the newly allocated concatenated string,
 *         or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int s1_len = 0, s2_len = 0;
	unsigned int concat_len, i, j;
	char *concat_str;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;

	concat_len = s1_len + s2_len;

	concat_str = malloc(sizeof(char) * (concat_len + 1));
	if (concat_str == NULL)
		return (NULL);

	for (i = 0; i < s1_len; i++)
		concat_str[i] = s1[i];

	for (j = 0; j < s2_len; j++)
		concat_str[i++] = s2[j];

	concat_str[i] = '\0';

	return (concat_str);
}
