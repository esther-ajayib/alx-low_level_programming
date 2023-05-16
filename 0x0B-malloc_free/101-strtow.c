#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
	int count = 0, i = 0, in_word = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
			i++;
	}

	return (count);
}

/**
 * allocate_words - Allocates memory for words array.
 * @str: The input string.
 * @word_count: The number of words in the string.
 *
 * Return: Pointer to the allocated words array.
 */
char **allocate_words(int word_count)
{
	char **words;

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	return (words);
}

/**
 * extract_word - Extracts a word from the input string.
 * @str: The input string.
 * @start: The starting index of the word in the string.
 * @end: The ending index of the word in the string.
 *
 * Return: The extracted word.
 */
char *extract_word(char *str, int start, int end)
{
	int i;
	int len = end - start;
	char *word;

	word = malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		word[i] = str[start++];
	word[i] = '\0';

	return (word);
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: Pointer to an array of strings (words),
 *         or NULL if str == NULL or if memory allocation fails.
 */
char **strtow(char *str)
{
	char **words;
	int word_count, i, j, k, len;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	words = allocate_words(word_count);
	if (words == NULL)
		return (NULL);

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			len = 0;
			k = i;
			while (str[k] != ' ' && str[k] != '\0')
			{
				len++;
				k++;
			}

			words[j] = extract_word(str, i, k);
			if (words[j] == NULL)
			{
				for (k = 0; k < j; k++)
					free(words[k]);
				free(words);
				return (NULL);
			}

			i = k;
			j++;
		}
		else
		{
			i++;
		}
	}

	words[j] = NULL;
	return (words);
}
