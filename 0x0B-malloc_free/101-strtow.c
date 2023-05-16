#include "main.h"
#include <stdlib.h>

/**
 * strtow - Splits a string into words
 * @str: The input string
 * Return: Pointer to an array of strings (words),
 *         or NULL if str is NULL or if memory allocation fails
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len = 0, word_count = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] != ' ' && str[i] != '\t') &&
			(str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			word_count++;
	}

	if (word_count == 0)
		return (NULL);
	
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, k= 0; str[i] != '\0' && k < word_count; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			len = 0;
			j = i;
			while ((str[j] != ' ' && str[j] != '\t') && str[j] != '\0')
			{
				len++;
				j++;
			}

			words[k] = malloc((len + 1) * sizeof(char));
			if (words[k] == NULL)
			{
				for (k = k - 1; k >= 0; k--)
					free(words[k]);
				free(words);
				return (NULL);
			}

			for (j = 0; j < len; j++, i++)
				words[k][j] = str[i];
			words[k][j] = '\0';
			k++;
		}
	}
	
	words[k] = NULL;
	return (words);
}
