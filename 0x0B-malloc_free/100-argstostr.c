#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments of the program.
 * @ac: The argument count.
 * @av: The argument vector.
 *
 * Return: Pointer to a new string containing concatenated arguments,
 *         or NULL if ac == 0 or av == NULL or on failure.
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, len, total_len = 0, index = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len] != '\0')
		{
			total_len++;
			len++;
		}
		total_len++;
	}

	str = malloc(sizeof(char) * (total_len + 1));
	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len] != '\0')
		{
			str[index] = av[i][len];
			index++;
			len++;
		}
		str[index] = '\n';
		index++;
	}
	str[index] = '\0';

	return (str);
}
