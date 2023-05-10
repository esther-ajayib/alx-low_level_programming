#include "main.h"

/**
 * get_string_length - Helper function to get the length of a string.
 * @s: The string.
 *
 * Return: The length of the string.
 */
int get_string_length(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + get_string_length(s + 1));
}

/**
 * is_palindrome_recursive - Helper function to check if a string is a palindrome recursively.
 * @s: The string.
 * @start: The starting index.
 * @end: The ending index.
 *
 * Return: 1 if palindrome, 0 otherwise.
 */
int is_palindrome_recursive(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (is_palindrome_recursive(s, start + 1, end - 1));
}

/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The string.
 *
 * Return: 1 if palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int length = get_string_length(s);
	int start = 0;
	int end = length - 1;

	return (is_palindrome_recursive(s, start, end));
}
